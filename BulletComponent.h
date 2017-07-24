//
// Created by cheburum on 20.07.17.
//

#ifndef SHOOTINGGALLERY_BULLETCOMPONENT_H
#define SHOOTINGGALLERY_BULLETCOMPONENT_H


#include "CleanManager.h"
#include "PhysComponent.h"
#include "SpriteComponent.h"

class BulletComponent : public Component {
private:
    sf::Clock clock;
    unsigned short collisionCounter;
    SpriteComponent* sprite;
    PhysComponent* physComponent;
public:
    BulletComponent(GameObject&);
    void update();
};


#endif //SHOOTINGGALLERY_BULLETCOMPONENT_H
