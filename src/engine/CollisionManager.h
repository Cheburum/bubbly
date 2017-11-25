#ifndef BUBBLYENGINE_COLLISIONMANAGER_H
#define BUBBLYENGINE_COLLISIONMANAGER_H

#include <vector>
#include "AbstractManager.h"

class PhysComponent;

//This class detects collisions of physics objects
class CollisionManager : public AbstractManager {
private:
    std::vector<PhysComponent *> objects;

    static bool checkCollisions(PhysComponent *, PhysComponent *);

public:
    void add(Component *const);

    void update();

    void remove(Component *const);
};


#endif //SHOOTINGGALLERY_PHYSWORLD_H
