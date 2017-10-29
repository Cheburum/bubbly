//
// Created by cheburum on 12.07.17.
//

#ifndef BUBBLYENGINE_GAMEOBJECT_H
#define BUBBLYENGINE_GAMEOBJECT_H


#include <forward_list>
#include <map>
#include <memory>
#include "Transform.h"

class Component;

class GlobalInfo;

class GameObject {
private:
    Transform transform;
    std::map<std::string, Component *> components;
    bool destroyed;
    GlobalInfo &info;
public:
    GameObject(GlobalInfo &gameWorld1);

    GameObject(const GameObject &other);

    GameObject(const GameObject &&other);

    GameObject &operator=(const GameObject &other);

    GameObject &operator=(const GameObject &&other);

    void update();

    void draw();

    void addComponent(const std::string &, Component *comp);

    GlobalInfo &getWorldInfo();

    bool containsComponent(const std::string &) const;

    bool containsComponent(Component *) const;

    bool isDestroyed() const;

    void destroy();

    Component *getComponent(const std::string &);

    Transform &getTransform();

    ~GameObject();
};


#endif //SHOOTINGGALLERY_GAMEOBJECT_H
