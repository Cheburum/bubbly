//
// Created by cheburum on 23.07.17.
//

#include "BubbleComponent.h"
#include "helpFunctions.h"

BubbleComponent::BubbleComponent(GameObject &obj):
        Component(obj),
        physComponent((PhysComponent*)obj.getComponent("Physics")) {
    clock.restart();
}

void BubbleComponent::update() {
    if(clock.getElapsedTime().asSeconds()>1.0f){
        physComponent->addImpulse(sf::Vector2f(randomFloat(-0.5f,0.5f),randomFloat(-0.5f,0.5f)));
        clock.restart();
    }
    for(auto& el: physComponent->getCollisions())
        if(!el->getGameObject().containsComponent("Bubble"))
            gameObject.destroy();
}