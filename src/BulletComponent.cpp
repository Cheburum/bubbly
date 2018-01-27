#include "BulletComponent.h"

BulletComponent::BulletComponent(GameObject& object)
        : Component(object),
          sprite(object.getComponent<SpriteComponent>("Sprite")),
          physComponent(gameObject.getComponent<PhysComponent>("Physics")),
          collisionCounter(0) {
    clock.restart();
}

void BulletComponent::update() {
    if (const auto collCount = physComponent.lock()->getCollisions().size();
        collCount>0){
        collisionCounter+=collCount;
        //auto &sfSprite = sprite.lock()->getSprite();
        //sfSprite.setColor(sfSprite.getColor()-sf::Color(30*collCount,30*collCount,30*collCount,0));
    }
    if (collisionCounter > 4 || clock.getElapsedTime() > 10.0f)
        gameObject.destroy();
}