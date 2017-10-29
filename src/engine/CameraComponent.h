//
// Created by cheburum on 25.10.17.
//

#ifndef BUBBLY_CAMERACOMPONENT_H
#define BUBBLY_CAMERACOMPONENT_H


#include "GameObject.h"
#include "Component.h"
#include <SFML/Graphics.hpp>

class CameraComponent : public Component{
private:
    bool isMain;
    sf::View sfmlView;
public:
    CameraComponent(GameObject& gameObject);
    void update();
    void setMain(bool);
};


#endif //BUBBLY_CAMERACOMPONENT_H
