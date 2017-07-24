//
// Created by cheburum on 15.07.17.
//

#ifndef SHOOTINGGALLERY_PHYSWORLD_H
#define SHOOTINGGALLERY_PHYSWORLD_H

#include <vector>
#include "AbstractManager.h"

class PhysComponent;
//This class detects collisions of physics objects
class CollisionManager : public AbstractManager {
private:
    std::vector<PhysComponent*> objects;
    static bool checkCollisions(PhysComponent*,PhysComponent*);
public:
    void add(Component* const);
    void update();
    void remove(Component* const);
};


#endif //SHOOTINGGALLERY_PHYSWORLD_H
