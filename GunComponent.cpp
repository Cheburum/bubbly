//
// Created by cheburum on 19.07.17.
//

#include <SFML/Window/Mouse.hpp>
#include "GunComponent.h"
#include "SpriteComponent.h"
#include "PhysComponent.h"
#include "GlobalInfo.h"
#include "BulletComponent.h"

GunComponent::GunComponent(GameObject& object,std::forward_list<GameObject>& container,float ypos,
const sf::Texture& bulletTexture1)
        :Component(object),
         gameObjects(container),
         bulletTexture(bulletTexture1),
        coolDown(1.0f){
    gameObject.getTransform().position.y=ypos;
    clock.restart();
    text.setFont(gameObject.getWorldInfo().getFont());
    text.setFillColor(sf::Color::Red);
}
void GunComponent::setForce(float x) {
    force=x;
}

void GunComponent::draw() {
    const auto t = coolDown - clock.getElapsedTime().asSeconds();
    if(t>0.0f) {
        text.setPosition(gameObject.getTransform().position + sf::Vector2f(50.0f, 0.0f));
        text.setString(std::to_string((int) t) + "." + std::to_string((int) (t * 10) % 10));
        gameObject.getWorldInfo().getWindow().draw(text);
    }
}

void GunComponent::update() {
    gameObject.getTransform().position.x=sf::Mouse::getPosition(gameObject.getWorldInfo().getWindow()).x;
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)&&clock.getElapsedTime().asSeconds()>coolDown){
        clock.restart();
        const auto scale = gameObject.getWorldInfo().screenW/bulletTexture.getSize().x/40.0f;
        gameObjects.push_front(GameObject(gameObject.getWorldInfo()));
        gameObjects.front().getTransform().scale*=scale;
        gameObjects.front().getTransform().position=gameObject.getTransform().position;
        const auto physComp = new PhysComponent(gameObjects.front(), 1.0f, true,true);
        gameObjects.front().addComponent("Physics",physComp);
        physComp->setCollider(Collider::circleCollider(bulletTexture.getSize().x*scale/2));
        physComp->addImpulse(sf::Vector2f(0.0f,-1.0f*force));
        gameObjects.front().addComponent("Sprite",new SpriteComponent(gameObjects.front(), bulletTexture));
        gameObjects.front().addComponent("Bullet",new BulletComponent(gameObjects.front()));
    }
}