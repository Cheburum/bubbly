#include "GameObject.h"
#include "Component.h"
#include "GlobalInfo.h"

GameObject::GameObject(GlobalInfo &gameWorld)
        : info(gameWorld), destroyed(false) {
}

void GameObject::update() {
    for (auto &el:components) {
        el.second->update();
    }
}

void GameObject::addComponent(const std::string &name, std::shared_ptr<Component> comp) {
    components[name] = comp;
}

void GameObject::addComponent(const std::string &name, Component *raw) {
    components[name] = std::shared_ptr < Component > (raw);
}

Transform &GameObject::getTransform() {
    return transform;
}

void GameObject::draw() {
    for (auto &el:components) {
        el.second->draw();
    }
}

GameObject::GameObject(const GameObject &other)
        : transform(other.transform),
          destroyed(false),
          info(other.info) {
}

GameObject::GameObject(const GameObject &&other)
        : transform(other.transform),
          destroyed(other.destroyed),
          info(other.info) {
    this->components = other.components;
}

GameObject &GameObject::operator=(const GameObject &other) {
    destroyed = other.destroyed;
    transform = other.transform;
    return *this;
}

GameObject &GameObject::operator=(const GameObject &&other) {
    destroyed = other.destroyed;
    transform = other.transform;
    this->components = other.components;
    return *this;
}

bool GameObject::containsComponent(const std::string &str) const {
    return components.find(str) != components.end();
}

void GameObject::destroy() {
    destroyed = true;
}

bool GameObject::isDestroyed() const {
    return destroyed;
}

GlobalInfo &GameObject::getWorldInfo() {
    return info;
}