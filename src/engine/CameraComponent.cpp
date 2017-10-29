//
// Created by cheburum on 25.10.17.
//

#include "CameraComponent.h"
#include "GlobalInfo.h"

CameraComponent::CameraComponent(GameObject &gameObject) : Component(gameObject) {
    sfmlView.reset(sf::FloatRect(0, 0,
                                 gameObject.getWorldInfo().screenW,
                                 gameObject.getWorldInfo().screenH));
}

void CameraComponent::setMain(bool x) {
    isMain = x;
    if (isMain)
        this->gameObject.getWorldInfo().getWindow().setView(sfmlView);
}

void CameraComponent::update() {
    sfmlView.setCenter(this->gameObject.getTransform().position);
}