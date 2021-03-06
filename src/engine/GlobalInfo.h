#ifndef BUBBLYENGINE_GLOBALINFO_H
#define BUBBLYENGINE_GLOBALINFO_H


#include <SFML/System/Clock.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include "CleanManager.h"
#include "CollisionManager.h"
#include <random>

class Scene;

class GlobalInfo {
private:
    sf::Clock clock;
    float pixelsPerUnit;
    sf::Vector2f gravity;
    sf::RenderWindow window;
    CollisionManager collisionDetector;
    sf::Font font;
    Scene &scene;
public:
    explicit GlobalInfo(Scene &);

    void onFrameDone();

    int getDeltaTime() const;

    float getPixelsPerUnit() const;

    const sf::Vector2f &getGravity() const;

    sf::RenderWindow &getWindow();

    CollisionManager &getCollisionDetector();

    const sf::Font &getFont();

    Scene &getScene();

    static constexpr int screenW = (1280); //width
    static constexpr int screenH = (720); //height
    static constexpr float screenWidthInUnits = 20;
    static constexpr float screenHeightInUnits = screenH / (screenW / screenWidthInUnits);
    std::default_random_engine random_generator;
};


#endif //SHOOTINGGALLERY_GLOBALINFO_H
