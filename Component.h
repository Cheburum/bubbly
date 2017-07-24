//
// Created by cheburum on 13.07.17.
//

#ifndef SHOOTINGGALLERY_COMPONENT_H
#define SHOOTINGGALLERY_COMPONENT_H

#include <memory>
#include "Transform.h"
class GameObject;
class Component {
protected:
    GameObject& gameObject;
public:
    Component(GameObject& gameObject);
    GameObject& getGameObject();
    virtual void update();
    virtual void draw();
    virtual ~Component();
    //virtual void fixedUpdate();
    //virtual void onLevelStart();
};


#endif //SHOOTINGGALLERY_COMPONENT_H
