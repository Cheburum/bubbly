//
// Created by cheburum on 20.07.17.
//

#ifndef SHOOTINGGALLERY_CLEANMANAGER_H
#define SHOOTINGGALLERY_CLEANMANAGER_H


#include <stack>
#include "AbstractManager.h"
#include "GameObject.h"

class CleanManager{
private:
    std::forward_list<GameObject>& gameObjects;
public:
    CleanManager(std::forward_list<GameObject>& arg);
    void afterUpdate();
};


#endif //SHOOTINGGALLERY_CLEANMANAGER_H