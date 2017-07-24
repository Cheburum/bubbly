//
// Created by cheburum on 12.07.17.
//

#include <SFML/Window/Event.hpp>
#include "Scene.h"
#include "TimerComponent.h"
#include "GunComponent.h"
#include "SpriteComponent.h"
#include "PhysComponent.h"
#include "BubbleComponent.h"

Scene::Scene():cleaner(gameObjects) {
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
    for (auto j = 0; j < 6; ++j)
        for (auto i = 0; i < 12; ++i)
            addBubble(sf::Vector2f(scale + 2 * scale * i, scale + 2 * j * scale));
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
    gameObjects.front().addComponent("Timer", new TimerComponent(gameObjects.front(),
                                                                 sf::Vector2f(info.screenW - 24 * 10, 24.0f),
                                                                 sf::Vector2f(1, 1), 13));
    //add boy
    gameObjects.push_front(GameObject(info));
    gameObjects.front().addComponent("Sprite", new SpriteComponent(gameObjects.front(), gunTexture));
    const auto gunScale = info.screenW / gunTexture.getSize().x / 10.0f;
    gameObjects.front().getTransform().scale = sf::Vector2f(gunScale, gunScale);
    const auto gunComponent = new GunComponent(gameObjects.front(),
                                               gameObjects,
                                               info.screenH - info.screenH / 22.0f,
                                               bulletTexture);
    gunComponent->setForce(30);
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

void Scene::addBubble(const sf::Vector2f &position) {
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
    gameObjects.front().addComponent("Bubble", new BubbleComponent(gameObjects.front()));
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

void Scene::startGameLoop() {
    while (info.getWindow().isOpen()) {
        sf::Event event;
        while (info.getWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                info.getWindow().close();
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