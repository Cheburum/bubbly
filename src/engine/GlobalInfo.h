#ifndef BUBBLYENGINE_GLOBALINFO_H
#define BUBBLYENGINE_GLOBALINFO_H

#include "CleanManager.h"
#include "CollisionManager.h"
#include "Window.h"
#include <random>
#include "Clock.h"

namespace Bubbly {
    class Scene;

    class GlobalInfo {
    private:
        Clock clock;
        float pixelsPerUnit;
        glm::vec2 gravity;
        Window window;
        CollisionManager collisionDetector;
        //TODO sf::Font font;
        Scene &scene;
    public:
        explicit GlobalInfo(Scene &);

        void onFrameDone();

        double getDeltaTime() const;

        float getPixelsPerUnit() const;

        const glm::vec2 &getGravity() const;

        Window &getWindow();

        CollisionManager &getCollisionDetector();

        //TODO const sf::Font &getFont();

        Scene &getScene();

        static constexpr int screenW = (1280); //width
        static constexpr int screenH = (720); //height
        static constexpr float screenWidthInUnits = 20;
        static constexpr float screenHeightInUnits = screenH / (screenW / screenWidthInUnits);
        std::default_random_engine random_generator;
    };

}
#endif
