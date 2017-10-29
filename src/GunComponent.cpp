//
// Created by cheburum on 19.07.17.
//

#include <SFML/Window/Mouse.hpp>
#include "GunComponent.h"
#include "engine/SpriteComponent.h"
#include "engine/PhysComponent.h"
#include "engine/GlobalInfo.h"
#include "BulletComponent.h"
#include "engine/Scene.h"
#include "engine/helpFunctions.h"
GunComponent::GunComponent(GameObject &object, float ypos,
                           const sf::Texture &bulletTexture1)
        : Component(object),
          bulletTexture(bulletTexture1),
          coolDown(1.0f) {
    gameObject.getTransform().position.y = ypos;
    clock.restart();
    text.setFont(gameObject.getWorldInfo().getFont());
    text.setFillColor(sf::Color::Red);
}

void GunComponent::setForce(float x) {
    force = x;
}

void GunComponent::draw() {
    const auto t = coolDown - clock.getElapsedTime().asSeconds();
    if (t > 0.0f) {
        text.setPosition(gameObject.getTransform().position     //TODO ADD TEXT COMPONENT
                         * gameObject.getWorldInfo().getPixelsPerUnit()
                         + sf::Vector2f(100.0f, 0.0f));
        text.setString(std::to_string((int) t) + "." + std::to_string((int) (t * 10) % 10));
        gameObject.getWorldInfo().getWindow().draw(text);
    }
}

void GunComponent::update() {
    gameObject.getTransform().position.x = sf::Mouse::getPosition(gameObject.getWorldInfo().getWindow()).x
                                           /gameObject.getWorldInfo().getPixelsPerUnit()
                                           - 0.5f;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && clock.getElapsedTime().asSeconds() > coolDown) {
        clock.restart();
        auto &newBullet = gameObject.getWorldInfo().getScene().createGameObject();
        newBullet.getTransform().position = gameObject.getTransform().position;
        const auto physComp = new PhysComponent(newBullet, 1.0f, true, true);
        newBullet.addComponent("Physics", physComp);
        physComp->setCollider(Collider::circleCollider(0.5f));
        physComp->addImpulse(sf::Vector2f(randomFloat(-5,5), -1.0f * force));
        newBullet.addComponent("Sprite", new SpriteComponent(newBullet, bulletTexture));
        newBullet.addComponent("Bullet", new BulletComponent(newBullet));
    }
}