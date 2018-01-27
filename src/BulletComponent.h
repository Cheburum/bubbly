#ifndef BUBBLY_BULLETCOMPONENT_H
#define BUBBLY_BULLETCOMPONENT_H


#include "engine/CleanManager.h"
#include "engine/PhysComponent.h"
#include "engine/SpriteComponent.h"
#include "engine/Clock.h"

using namespace Bubbly;

class BulletComponent : public Component {
private:
    Clock clock;
    unsigned short collisionCounter;
    std::weak_ptr<SpriteComponent> sprite;
    std::weak_ptr<PhysComponent> physComponent;
public:
    explicit BulletComponent(GameObject &);

    void update();
};


#endif
