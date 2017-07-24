//
// Created by cheburum on 12.07.17.
//

#ifndef SHOOTINGGALLERY_GAMEFIELD_H
#define SHOOTINGGALLERY_GAMEFIELD_H


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include "GlobalInfo.h"
#include "GameObject.h"
#include "CollisionManager.h"
#include "CleanManager.h"

class Scene {
private:
    GlobalInfo info;
    sf::Sprite background;
    void update();
    void draw();
    std::forward_list<GameObject> gameObjects;
    CleanManager cleaner;
    sf::Texture bubbleTexture;
    sf::Texture backgroundTexture;
    sf::Texture gunTexture;
    sf::Texture bulletTexture;
    void addBubble(const sf::Vector2f& arg);
    void addWall(const sf::Vector2f& size, const sf::Vector2f& position);
public:
    Scene();
    void startGameLoop();
};


#endif //SHOOTINGGALLERY_GAMEFIELD_H
