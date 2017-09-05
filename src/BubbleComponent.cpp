//
// Created by cheburum on 23.07.17.
//

#include "BubbleComponent.h"
#include "engine/helpFunctions.h"

BubbleComponent::BubbleComponent(GameObject &obj,CounterComponent& counter):
        Component(obj),
        physComponent((PhysComponent*)obj.getComponent("Physics")),
        counter(counter){
    ++counter;
    clock.restart();
}

void BubbleComponent::update() {
    if(clock.getElapsedTime().asSeconds()>1.0f){
        physComponent->addImpulse(sf::Vector2f(randomFloat(-0.5f,0.5f),randomFloat(-0.5f,0.5f)));
        clock.restart();
    }
    for(auto& el: physComponent->getCollisions())
        if(el->getGameObject().containsComponent("Bullet")) {
            --counter;
            gameObject.destroy();
        }
}