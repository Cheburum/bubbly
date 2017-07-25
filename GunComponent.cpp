//
// Created by cheburum on 19.07.17.
//

#include <SFML/Window/Mouse.hpp>
#include "GunComponent.h"
#include "SpriteComponent.h"
#include "PhysComponent.h"
#include "GlobalInfo.h"
#include "BulletComponent.h"
#include "Scene.h"

GunComponent::GunComponent(GameObject& object,float ypos,
const sf::Texture& bulletTexture1)
        :Component(object),
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
        auto& newBullet=gameObject.getWorldInfo().getScene().createGameObject();
        newBullet.getTransform().scale*=scale;
        newBullet.getTransform().position=gameObject.getTransform().position;
        const auto physComp = new PhysComponent(newBullet, 1.0f, true,true);
        newBullet.addComponent("Physics",physComp);
        physComp->setCollider(Collider::circleCollider(bulletTexture.getSize().x*scale/2));
        physComp->addImpulse(sf::Vector2f(0.0f,-1.0f*force));
        newBullet.addComponent("Sprite",new SpriteComponent(newBullet, bulletTexture));
        newBullet.addComponent("Bullet",new BulletComponent(newBullet));
    }
}