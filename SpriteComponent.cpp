//
// Created by cheburum on 13.07.17.
//

#include "SpriteComponent.h"
#include "GameObject.h"
#include "GlobalInfo.h"
#include <SFML/Graphics.hpp>

SpriteComponent::SpriteComponent(GameObject& gameObject1)
        :Component(gameObject1) {
    sprite.setPosition(gameObject1.getTransform().position);
    sprite.setRotation(gameObject1.getTransform().rotation);
    sprite.setScale(gameObject1.getTransform().scale);
}
SpriteComponent::SpriteComponent(GameObject& gameObject1,const sf::Texture &texture)
        :Component(gameObject1) {
    sprite.setPosition(gameObject1.getTransform().position);
    sprite.setRotation(gameObject1.getTransform().rotation);
    sprite.setScale(gameObject1.getTransform().scale);
    setTexture(texture);
}
void SpriteComponent::setTexture(const sf::Texture &texture) {
    sprite.setTexture(texture, true);
    //pivot to center
    sprite.setOrigin(texture.getSize().x/2.0f,texture.getSize().y/2.0f);
}
sf::Sprite& SpriteComponent::getSprite() {
    return sprite;
}

void SpriteComponent::update() {
    sprite.setPosition(gameObject.getTransform().position);
    sprite.setRotation(gameObject.getTransform().rotation);
    sprite.setScale(gameObject.getTransform().scale);
}

void SpriteComponent::draw() {
    gameObject.getWorldInfo().getWindow().draw(sprite);
}