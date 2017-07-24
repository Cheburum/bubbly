//
// Created by cheburum on 12.07.17.
//

#include <SFML/Window/Event.hpp>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Scene.h"
#include "TimerComponent.h"
#include "GunComponent.h"
#include "SpriteComponent.h"
#include "PhysComponent.h"
#include "BubbleComponent.h"

Scene::Scene():cleaner(gameObjects),needReload(true),info(*this) {}

GameConfig Scene::loadConfig() {
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

void Scene::loadLevel() {
    const auto cfg = loadConfig();
    //Loading textures
    //background
    if (!backgroundTexture.loadFromFile("../images/bg.png")) {

    };
    backgroundTexture.setSmooth(true);
    background.setTexture(backgroundTexture, false);
    background.setScale(info.screenW / (float) backgroundTexture.getSize().x,
                        info.screenH / (float) backgroundTexture.getSize().y);
    //bubble texture
    if (!bubbleTexture.loadFromFile("../images/circle.png")) {

    }; //TODO handle no file errors and etc.
    bubbleTexture.setSmooth(true);
    const auto scale = info.screenW / 25.0f;
    //adding gameobjects
    //bubble counter
    gameObjects.push_front(GameObject(info));
    auto bubbleCounter = new CounterComponent(gameObjects.front());
    gameObjects.front().addComponent("BubbleCounter",bubbleCounter);
    for (auto j = 0,k=0; j < 6&&k<cfg.countTarget; ++j)
        for (auto i = 0; i < 12&&k<cfg.countTarget; ++i,++k)
            addBubble(sf::Vector2f(scale + 2 * scale * i, scale + 2 * j * scale),*bubbleCounter);
    //Bottom border
    addWall(sf::Vector2f(info.screenW, 30.0f), sf::Vector2f(info.screenW / 2, info.screenH + 15.0f));
    //top border
    addWall(sf::Vector2f(info.screenW, 30.0f), sf::Vector2f(info.screenW / 2, -15.0f));
    //left
    addWall(sf::Vector2f(30.0f, info.screenH), sf::Vector2f(-15.0f, info.screenH / 2));
    //right
    addWall(sf::Vector2f(30.0f, info.screenH), sf::Vector2f(info.screenW + 15.0f, info.screenH / 2));
    if (!gunTexture.loadFromFile("../images/pinky.png")) {

    }
    gunTexture.setSmooth(true);
    if (!bulletTexture.loadFromFile("../images/duck.png")) {

    }
    gunTexture.setSmooth(true);
    //add timer
    gameObjects.push_front(GameObject(info));
    gameObjects.front().getTransform().position=sf::Vector2f(info.screenW - 24 * 10, 24.0f);
    gameObjects.front().addComponent("Timer", new TimerComponent(gameObjects.front(),*bubbleCounter,cfg.time));
    //add boy
    gameObjects.push_front(GameObject(info));
    gameObjects.front().addComponent("Sprite", new SpriteComponent(gameObjects.front(), gunTexture));
    const auto gunScale = info.screenW / gunTexture.getSize().x / 10.0f;
    gameObjects.front().getTransform().scale = sf::Vector2f(gunScale, gunScale);
    const auto gunComponent = new GunComponent(gameObjects.front(),
                                               gameObjects,
                                               info.screenH - info.screenH / 22.0f,
                                               bulletTexture);
    gunComponent->setForce(cfg.speed);
    gameObjects.front().addComponent("Gun",gunComponent);
}

void Scene::addWall(const sf::Vector2f &size, const sf::Vector2f &position) {
    gameObjects.push_front(GameObject(info));
    gameObjects.front().addComponent("Physics",
                                     new PhysComponent(gameObjects.front(), 0.0f, false, false));
    const auto currentPhysComponent = (PhysComponent *) gameObjects.front().getComponent("Physics");
    currentPhysComponent->setCollider(Collider::rectangleCollider(size));
    gameObjects.front().getTransform().position = position;
}

void Scene::addBubble(const sf::Vector2f &position,CounterComponent& counter) {
    gameObjects.push_front(GameObject(info));
    gameObjects.front().addComponent("Sprite",
                                     new SpriteComponent(gameObjects.front(), bubbleTexture));
    gameObjects.front().addComponent("Physics",
                                     new PhysComponent(gameObjects.front(), 1.0f, false, true));
    const auto currentPhysComponent = (PhysComponent *) gameObjects.front().getComponent("Physics");
    const auto scale = info.screenW / bubbleTexture.getSize().x / 20.0f;
    currentPhysComponent->setCollider(Collider::circleCollider(bubbleTexture.getSize().x * scale / 2));
    gameObjects.front().getTransform().scale = sf::Vector2f(scale, scale);
    gameObjects.front().getTransform().position += position;
    gameObjects.front().addComponent("Bubble", new BubbleComponent(gameObjects.front(),counter));
}

void Scene::update() {
    info.getCollisionDetector().update();
    for (auto &el:gameObjects)
        el.update();
}

void Scene::draw() {
    for (auto &el:gameObjects)
        el.draw();
}

void Scene::reload() {
    needReload=true;
}

void Scene::startGameLoop() {
    while (info.getWindow().isOpen()) {
        sf::Event event;
        while (info.getWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                info.getWindow().close();
        }
        if(needReload){
            gameObjects.clear();
            loadLevel();
            needReload=false;
        }
        info.getWindow().clear(sf::Color::Blue);
        info.getWindow().draw(background);
        this->update();
        this->draw();
        this->info.onFrameDone();
        cleaner.afterUpdate();
        info.getWindow().display();
    }
}