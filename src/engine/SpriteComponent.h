//
// Created by cheburum on 13.07.17.
//

#ifndef BUBBLYENGINE_SPRITECOMPONENT_H
#define BUBBLYENGINE_SPRITECOMPONENT_H


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Component.h"

class SpriteComponent: public Component{
private:
    sf::Sprite sprite;
public:
    SpriteComponent(GameObject& gameObject1);
    SpriteComponent(GameObject& transform,const sf::Texture& texture);
    sf::Sprite& getSprite();
    void setTexture(const sf::Texture& texture);
    void update();
    void draw();
};


#endif //SHOOTINGGALLERY_SPRITECOMPONENT_H
