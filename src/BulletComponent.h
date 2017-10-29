//
// Created by cheburum on 20.07.17.
//

#ifndef BUBBLY_BULLETCOMPONENT_H
#define BUBBLY_BULLETCOMPONENT_H


#include "engine/CleanManager.h"
#include "engine/PhysComponent.h"
#include "engine/SpriteComponent.h"

class BulletComponent : public Component {
private:
    sf::Clock clock;
    unsigned short collisionCounter;
    SpriteComponent *sprite;
    PhysComponent *physComponent;
public:
    BulletComponent(GameObject &);

    void update();
};


#endif //SHOOTINGGALLERY_BULLETCOMPONENT_H
