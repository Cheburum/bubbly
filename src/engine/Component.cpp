//
// Created by cheburum on 13.07.17.
//

#include "Component.h"
#include "GameObject.h"

Component::Component(GameObject &obj) : gameObject(obj) {

}

void Component::update() {}

void Component::draw() {}

GameObject &Component::getGameObject() {
    return gameObject;
}

Component::~Component() {}