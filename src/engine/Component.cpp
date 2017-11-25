#include "Component.h"
#include "GameObject.h"

Component::Component(GameObject &obj) : gameObject(obj) {

}

void Component::update() {}

void Component::draw() {}

GameObject &Component::getGameObject() {
    return gameObject;
}

Component::~Component() = default;