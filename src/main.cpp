#include "engine/Scene.h"
#include "engine/SpriteComponent.h"
#include "engine/PhysComponent.h"
#include "TimerComponent.h"
#include "BubbleComponent.h"
#include "GunComponent.h"
#include <fstream>
#include <iostream>
#include <sstream>

struct GameConfig{
    unsigned int countTarget;
    unsigned int speed;
    unsigned int time;
};


class Game{
private:
    sf::Texture bubbleTexture;
    sf::Texture backgroundTexture;
    sf::Texture gunTexture;
    sf::Texture bulletTexture;
    Scene scene;
    void addBubble(const sf::Vector2f& arg,CounterComponent& counter){
        auto& newGameObject = scene.createGameObject();
        newGameObject.addComponent("Sprite",
                                   new SpriteComponent(newGameObject, bubbleTexture));
        newGameObject.addComponent("Physics",
                                   new PhysComponent(newGameObject, 1.0f, false, true));
        const auto currentPhysComponent = (PhysComponent *) newGameObject.getComponent("Physics");
        const auto scale = scene.getInfo().screenW / bubbleTexture.getSize().x / 20.0f;
        currentPhysComponent->setCollider(Collider::circleCollider(bubbleTexture.getSize().x * scale / 2));
        newGameObject.getTransform().scale = sf::Vector2f(scale, scale);
        newGameObject.getTransform().position += arg;
        newGameObject.addComponent("Bubble", new BubbleComponent(newGameObject,counter));
    }
    void addWall(const sf::Vector2f &size, const sf::Vector2f &position) {
        auto& newGameObject = scene.createGameObject();
        newGameObject.addComponent("Physics",
                                   new PhysComponent(newGameObject, 0.0f, false, false));
        const auto currentPhysComponent = (PhysComponent *) newGameObject.getComponent("Physics");
        currentPhysComponent->setCollider(Collider::rectangleCollider(size));
        newGameObject.getTransform().position = position;
    }

    GameConfig loadConfig() {
        GameConfig cfg={1,1,1};
        std::ifstream file("../gameConfig/input.txt");
        for(std::string line;std::getline(file,line);){
            std::istringstream stream(line);
            std::string key,value;
            bool ok=std::getline(stream,key,'=')&&std::getline(stream,value);
            std::cout<<key<<'='<<value<<std::endl;
            if(ok){
                if(key.compare("CountTarget")==0)
                    cfg.countTarget=std::stoul(value);
                else if(key.compare("Speed")==0)
                    cfg.speed=std::stoul(value);
                else if(key.compare("Time")==0)
                    cfg.time=std::stoul(value);
            }

        }
        return cfg;
    }
    void loadLevel(){
        const auto cfg = loadConfig();
        //Loading textures
        //background
        if (!backgroundTexture.loadFromFile("../images/bg.png")) {

        };
        backgroundTexture.setSmooth(true);
        scene.setBackground(backgroundTexture);
        //bubble texture
        if (!bubbleTexture.loadFromFile("../images/circle.png")) {

        }; //TODO handle no file errors and etc.
        bubbleTexture.setSmooth(true);
        const auto scale = scene.getInfo().screenW / 25.0f;
        //adding gameobjects
        //bubble counter
        auto& bubbleObject = scene.createGameObject();
        auto bubbleCounter = new CounterComponent(bubbleObject);
        bubbleObject.addComponent("BubbleCounter",bubbleCounter);

        for (auto j = 0,k=0; j < 6&&k<cfg.countTarget; ++j)
            for (auto i = 0; i < 12&&k<cfg.countTarget; ++i,++k)
                addBubble(sf::Vector2f(scale + 2 * scale * i, scale + 2 * j * scale),*bubbleCounter);
        //Bottom border
        addWall(sf::Vector2f(scene.getInfo().screenW, 30.0f),
                sf::Vector2f(scene.getInfo().screenW / 2,
                             scene.getInfo().screenH + 15.0f));
        //top border
        addWall(sf::Vector2f(scene.getInfo().screenW, 30.0f),
                sf::Vector2f(scene.getInfo().screenW / 2, -15.0f));
        //left
        addWall(sf::Vector2f(30.0f, scene.getInfo().screenH),
                sf::Vector2f(-15.0f, scene.getInfo().screenH / 2));
        //right
        addWall(sf::Vector2f(30.0f, scene.getInfo().screenH),
                sf::Vector2f(scene.getInfo().screenW + 15.0f, scene.getInfo().screenH / 2));
        if (!gunTexture.loadFromFile("../images/pinky.png")) {

        }
        gunTexture.setSmooth(true);
        if (!bulletTexture.loadFromFile("../images/duck.png")) {

        }
        gunTexture.setSmooth(true);
        //add timer
        auto& timerObject = scene.createGameObject();
        timerObject.getTransform().position=sf::Vector2f(scene.getInfo().screenW - 24 * 10, 24.0f);
        timerObject.addComponent("Timer", new TimerComponent(timerObject,*bubbleCounter,cfg.time));
        //add boy
        auto& boyObject = scene.createGameObject();
        boyObject.addComponent("Sprite", new SpriteComponent(boyObject, gunTexture));
        const auto gunScale = scene.getInfo().screenW / gunTexture.getSize().x / 10.0f;
        boyObject.getTransform().scale = sf::Vector2f(gunScale, gunScale);
        const auto gunComponent = new GunComponent(boyObject,
                                                   scene.getInfo().screenH - scene.getInfo().screenH / 22.0f,
                                                   bulletTexture);
        gunComponent->setForce(cfg.speed);
        boyObject.addComponent("Gun",gunComponent);
    }
public:
    Game():scene(std::bind(&Game::loadLevel,this)){}
    void start(){
        scene.startGameLoop();
    }
};

int main() {
    srand(time(NULL));
    Game game;
    game.start();
    return 0;
}