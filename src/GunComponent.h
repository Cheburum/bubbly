#ifndef SHOOTINGGALLERY_GUNCOMPONENT_H
#define SHOOTINGGALLERY_GUNCOMPONENT_H

#include "engine/Component.h"
#include "engine/GameObject.h"
#include "engine/CollisionManager.h"
#include "engine/Clock.h"
#include "engine/Texture.h"

using namespace Bubbly;

class GunComponent : public Component {
private:
    const Texture &bulletTexture;
    Clock clock;
    float force;
    //TODO sf::Text text;
    float coolDown;
public:
    GunComponent(GameObject &object, float ypos,
                 const Texture &texture);

    void update();

    void draw();

    void setForce(float);
};


#endif
