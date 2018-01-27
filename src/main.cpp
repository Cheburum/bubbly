#include "engine/Scene.h"
#include "engine/SpriteComponent.h"
#include "engine/PhysComponent.h"
#include "TimerComponent.h"
#include "BubbleComponent.h"
#include "GunComponent.h"
#include <fstream>
#include <iostream>
#include <sstream>

struct GameConfig {
    unsigned long countTarget;
    unsigned long speed;
    unsigned long time;
};


class Game {
private:
    Texture bubbleTexture;
    Texture backgroundTexture;
    Texture gunTexture;
    Texture bulletTexture;
    Scene scene;

    void addBubble(const glm::vec2 &arg, CounterComponent &counter) {
        auto &newGameObject = scene.createGameObject();
        newGameObject.addComponent("Sprite", new SpriteComponent(newGameObject, bubbleTexture));
        newGameObject.addComponent("Physics",
                                   new PhysComponent(newGameObject, 1.0f, false, true));
        const auto currentPhysComponent = newGameObject.getComponent<PhysComponent>("Physics");
        currentPhysComponent.lock()->setCollider(Collider::circleCollider(0.5f));
        newGameObject.getTransform().position = arg;
        newGameObject.addComponent("Bubble", new BubbleComponent(newGameObject, counter));
    }

    void addWall(const glm::vec2 &size, const glm::vec2 &position) {
        auto &newGameObject = scene.createGameObject();
        newGameObject.addComponent("Physics",
                                   new PhysComponent(newGameObject, 0.0f, false, false));
        const auto currentPhysComponent = newGameObject.getComponent<PhysComponent>("Physics");
        currentPhysComponent.lock()->setCollider(Collider::rectangleCollider(size));
        newGameObject.getTransform().position = position;
    }

    GameConfig loadConfig() {
        GameConfig cfg = {1, 1, 1};
        std::ifstream file("../gameConfig/input.txt");
        for (std::string line; std::getline(file, line);) {
            std::istringstream stream(line);
            std::string key, value;
            bool ok = std::getline(stream, key, '=') && std::getline(stream, value);
            std::cout << key << '=' << value << std::endl;
            if (ok) {
                if (key.compare("CountTarget") == 0)
                    cfg.countTarget = std::stoul(value);
                else if (key.compare("Speed") == 0)
                    cfg.speed = std::stoul(value);
                else if (key.compare("Time") == 0)
                    cfg.time = std::stoul(value);
            }

        }
        return cfg;
    }

    void loadLevel() {
        const auto cfg = loadConfig();
        //Loading textures
        //background
        if (!backgroundTexture.loadFromFile("../images/bg.png")) {

        };
        //backgroundTexture.setSmooth(true); TODO
        scene.setBackground(backgroundTexture);
        //bubble texture
        if (!bubbleTexture.loadFromFile("../images/circle.png")) {

        }; //TODO handle no file errors and etc.
        // bubbleTexture.setSmooth(true);
        //adding gameobjects
        //bubble counter
        auto &bubbleObject = scene.createGameObject();
        auto bubbleCounter = new CounterComponent(bubbleObject);
        bubbleObject.addComponent("BubbleCounter", bubbleCounter);

        for (auto j = 0, k = 0; k < cfg.countTarget; ++j)
            for (auto i = 0; i < 10 && k < cfg.countTarget; ++i, ++k)
                addBubble(glm::vec2(0.5f + 2 * i, 0.5f + 2 * j), *bubbleCounter);

        const auto screenW = scene.getInfo().screenWidthInUnits;
        const auto screenH = scene.getInfo().screenHeightInUnits;
        //Bottom border

        addWall(glm::vec2(screenW, 0.5f),
                glm::vec2(screenW / 2,
                          screenH - 0.25f));
        //top border
        addWall(glm::vec2(screenW, 0.5f),
                glm::vec2(screenW / 2, -0.75f));
        //left
        addWall(glm::vec2(0.5f, screenH),
                glm::vec2(-0.75f, screenH / 2));
        //right
        addWall(glm::vec2(0.5f, screenH),
                glm::vec2(screenW - 0.25f, screenH / 2));
        if (!gunTexture.loadFromFile("../images/pinky.png")) {

        }
        //gunTexture.setSmooth(true);
        if (!bulletTexture.loadFromFile("../images/duck.png")) {

        }
        //gunTexture.setSmooth(true);
        //add timer
        auto &timerObject = scene.createGameObject();
        timerObject.getTransform().position = glm::vec2(scene.getInfo().screenW - 24 * 10, 24.0f);
        timerObject.addComponent("Timer", new TimerComponent(timerObject, *bubbleCounter, cfg.time));
        //add boy
        auto &boyObject = scene.createGameObject();
        boyObject.addComponent("Sprite", new SpriteComponent(boyObject, gunTexture));
        const auto gunComponent = new GunComponent(boyObject,
                                                   screenH - 1,
                                                   bulletTexture);
        gunComponent->setForce(cfg.speed / 2);
        boyObject.addComponent("Gun", gunComponent);

        //Add camera
        auto& camera = scene.createGameObject();
        const auto camComp = new CameraComponent(camera);
        camera.addComponent("Camera", camComp);
        camComp->setMain(true);
    }

public:
    Game() : scene(std::bind(&Game::loadLevel, this)) {}

    void start() {
        scene.startGameLoop();
    }
};

int main() {
    srand(time(NULL));
    Game game;
    game.start();
    return 0;
}