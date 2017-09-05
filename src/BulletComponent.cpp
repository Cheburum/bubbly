//
// Created by cheburum on 20.07.17.
//

#include "BulletComponent.h"

BulletComponent::BulletComponent(GameObject& object)
        :Component(object),
         sprite((SpriteComponent*)object.getComponent("Sprite")),
         physComponent((PhysComponent*)gameObject.getComponent("Physics")),
         collisionCounter(0){
    clock.restart();
}

void BulletComponent::update() {
    if(const auto collCount = physComponent->getCollisions().size();
        collCount>0){
        collisionCounter+=collCount;
        auto& sfSprite = sprite->getSprite();
        sfSprite.setColor(sfSprite.getColor()-sf::Color(30*collCount,30*collCount,30*collCount,0));
    }
    if(collisionCounter>4||clock.getElapsedTime().asSeconds()>10.0f)
        gameObject.destroy();
}