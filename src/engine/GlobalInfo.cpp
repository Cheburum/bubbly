#include "GlobalInfo.h"

GlobalInfo::GlobalInfo(Scene &scene1)
        : gravity(0.0, 9.81f),
          pixelsPerUnit(screenW/screenWidthInUnits),
          window(sf::VideoMode(screenW, screenH),
                 "Bubble game", sf::Style::Close),
          scene(scene1) {
    if (!font.loadFromFile("../fonts/Boxy-Bold.ttf")) {
        //TODO
    }
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    clock.restart();
}

Scene &GlobalInfo::getScene() {
    return scene;
}

sf::RenderWindow &GlobalInfo::getWindow() {
    return window;
}

const sf::Vector2f &GlobalInfo::getGravity() const {
    return gravity;
}

float GlobalInfo::getPixelsPerUnit() const {
    return pixelsPerUnit;
}

int GlobalInfo::getDeltaTime() const {
    return clock.getElapsedTime().asMilliseconds();
}

void GlobalInfo::onFrameDone() {

    clock.restart();
}

CollisionManager &GlobalInfo::getCollisionDetector() {
    return collisionDetector;
}

const sf::Font &GlobalInfo::getFont() {
    return font;
}