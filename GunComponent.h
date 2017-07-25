//
// Created by cheburum on 19.07.17.
//

#ifndef SHOOTINGGALLERY_GUNCOMPONENT_H
#define SHOOTINGGALLERY_GUNCOMPONENT_H


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Component.h"
#include "GameObject.h"
#include "CollisionManager.h"

class GunComponent : public Component {
private:
    const sf::Texture& bulletTexture;
    sf::Clock clock;
    float force;
    sf::Text text;
    float coolDown;
public:
    GunComponent(GameObject& object,float ypos,
                 const sf::Texture& texture);
    void update();
    void draw();
    void setForce(float);
};


#endif //SHOOTINGGALLERY_GUNCOMPONENT_H
