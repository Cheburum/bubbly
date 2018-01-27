#include "CameraComponent.h"
#include "GlobalInfo.h"

namespace Bubbly {
    CameraComponent::CameraComponent(GameObject &gameObject) :
            Component(gameObject),
            isMain(false) {
        //TODO sfmlView.reset(sf::FloatRect(0, 0,
        //                              gameObject.getWorldInfo().screenW,
        //                              gameObject.getWorldInfo().screenH));
    }

    void CameraComponent::setMain(bool x) {
        isMain = x;
        if (isMain);
        //TODO    this->gameObject.getWorldInfo().getWindow().setView(sfmlView);
    }

    void CameraComponent::update() {
        //TODO sfmlView.setCenter(this->gameObject.getTransform().position);
    }
}