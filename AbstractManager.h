//
// Created by cheburum on 20.07.17.
//

#ifndef SHOOTINGGALLERY_ABSTRACTMANAGER_H
#define SHOOTINGGALLERY_ABSTRACTMANAGER_H


#include "Component.h"

class AbstractManager {
public:
    virtual void add(Component*);
    virtual void update();
    virtual void remove(Component*);
};


#endif //SHOOTINGGALLERY_ABSTRACTMANAGER_H
