#ifndef BUBBLY_BULLETCOMPONENT_H
#define BUBBLY_BULLETCOMPONENT_H


#include "engine/CleanManager.h"
#include "engine/PhysComponent.h"
#include "engine/SpriteComponent.h"

class BulletComponent : public Component {
private:
    sf::Clock clock;
    unsigned short collisionCounter;
    std::weak_ptr<SpriteComponent> sprite;
    std::weak_ptr<PhysComponent> physComponent;
public:
    explicit BulletComponent(GameObject &);

    void update();
};


#endif //SHOOTINGGALLERY_BULLETCOMPONENT_H
