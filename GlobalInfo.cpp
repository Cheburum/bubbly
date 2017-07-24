//
// Created by cheburum on 13.07.17.
//

#include "GlobalInfo.h"

GlobalInfo::GlobalInfo()
        : gravity(0.0, 9.81f),
          pixelsPerMeter(40.0f),
          window(sf::VideoMode(screenW, screenH),
                 "Bubble game", sf::Style::Close) {
    if(!font.loadFromFile("../fonts/Boxy-Bold.ttf")){
        //TODO
    }
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    clock.restart();
}

sf::RenderWindow& GlobalInfo::getWindow(){
    return window;
}
const sf::Vector2f& GlobalInfo::getGravity() const {
    return gravity;
}

float GlobalInfo::getPixelsPerMeter() const {
    return pixelsPerMeter;
}

int GlobalInfo::getDeltaTime() const {
    return clock.getElapsedTime().asMilliseconds();
}

void GlobalInfo::onFrameDone() {

    clock.restart();
}
CollisionManager& GlobalInfo::getCollisionDetector() {
    return collisionDetector;
}
const sf::Font& GlobalInfo::getFont() {
    return font;
}