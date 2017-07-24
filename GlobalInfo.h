//
// Created by cheburum on 13.07.17.
//

#ifndef SHOOTINGGALLERY_GLOBALINFO_H
#define SHOOTINGGALLERY_GLOBALINFO_H


#include <SFML/System/Clock.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include "CleanManager.h"
#include "CollisionManager.h"

class GlobalInfo {
private:
    sf::Clock clock;
    float pixelsPerMeter;
    sf::Vector2f gravity;
    sf::RenderWindow window;
    CollisionManager collisionDetector;
    sf::Font font;
public:
    GlobalInfo();
    void onFrameDone();
    int getDeltaTime() const;
    float getPixelsPerMeter() const;
    const sf::Vector2f& getGravity() const;
    sf::RenderWindow& getWindow();
    CollisionManager& getCollisionDetector();
    const sf::Font& getFont();
    static const int screenW = 1280; //width
    static const int screenH = 720; //height
};


#endif //SHOOTINGGALLERY_GLOBALINFO_H
