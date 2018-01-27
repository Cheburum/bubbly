#include "GlobalInfo.h"

namespace Bubbly {
    GlobalInfo::GlobalInfo(Scene &scene1)
            : gravity(0.0, 9.81f),
              pixelsPerUnit(screenW / screenWidthInUnits),
              window(1280, 720, "Hello, world"),
              scene(scene1) {
        // if (!font.loadFromFile("../fonts/Boxy-Bold.ttf")) {
        //TODO
        //}
        //TODO window.setFramerateLimit(60);
        //TODO window.setVerticalSyncEnabled(true);
        clock.restart();
    }

    Scene &GlobalInfo::getScene() {
        return scene;
    }

    Bubbly::Window &GlobalInfo::getWindow() {
        return window;
    }

    const glm::vec2 &GlobalInfo::getGravity() const {
        return gravity;
    }

    float GlobalInfo::getPixelsPerUnit() const {
        return pixelsPerUnit;
    }

    double GlobalInfo::getDeltaTime() const {
        return clock.getElapsedTime();
    }

    void GlobalInfo::onFrameDone() {

        clock.restart();
    }

    CollisionManager &GlobalInfo::getCollisionDetector() {
        return collisionDetector;
    }
/* TODO
const sf::Font &GlobalInfo::getFont() {
    return font;
}*/
}