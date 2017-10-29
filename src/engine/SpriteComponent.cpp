//
// Created by cheburum on 13.07.17.
//

#include "SpriteComponent.h"
#include "GameObject.h"
#include "GlobalInfo.h"
#include <SFML/Graphics.hpp>

sf::Vector2f SpriteComponent::getScaleToUnits(sf::Vector2f units) const {
    const auto pixelsPerUnit = gameObject.getWorldInfo().getPixelsPerUnit();
    return sf::Vector2f(pixelsPerUnit/textureSize.x * units.x,
                        pixelsPerUnit/textureSize.y * units.y);
}

SpriteComponent::SpriteComponent(GameObject &gameObject1)
        : Component(gameObject1) {
    const auto pixelsPerUnit = gameObject.getWorldInfo().getPixelsPerUnit();
    sprite.setPosition(gameObject1.getTransform().position * pixelsPerUnit);
    sprite.setRotation(gameObject1.getTransform().rotation);
    sprite.setScale((getScaleToUnits(gameObject.getTransform().scale)));
}

SpriteComponent::SpriteComponent(GameObject &gameObject1, const sf::Texture &texture)
        : Component(gameObject1) {
    textureSize = sf::Vector2f(texture.getSize().x,texture.getSize().y);
    sprite.setPosition(gameObject1.getTransform().position);
    sprite.setRotation(gameObject1.getTransform().rotation);
    sprite.setScale(getScaleToUnits(gameObject.getTransform().scale));
    setTexture(texture);
}

void SpriteComponent::setTexture(const sf::Texture &texture) {
    textureSize = sf::Vector2f(texture.getSize().x,texture.getSize().y);
    sprite.setTexture(texture, true);
    //pivot to center
    sprite.setOrigin(gameObject.getTransform().scale);
    sprite.setScale(getScaleToUnits(gameObject.getTransform().scale));
}

sf::Sprite &SpriteComponent::getSprite() {
    return sprite;
}

void SpriteComponent::update() {

}

void SpriteComponent::draw() {
    const auto pixelsPerUnit = gameObject.getWorldInfo().getPixelsPerUnit();
    sprite.setPosition(gameObject.getTransform().position * pixelsPerUnit);
    sprite.setRotation(gameObject.getTransform().rotation);
    sprite.setScale(getScaleToUnits(gameObject.getTransform().scale));
    gameObject.getWorldInfo().getWindow().draw(sprite);
}