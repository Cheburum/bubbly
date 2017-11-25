#include <SFML/Window/Event.hpp>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Scene.h"
#include "PhysComponent.h"

Scene::Scene(std::function<void()> fun) : cleaner(gameObjects),
                                          needReload(true),
                                          info(*this),
                                          backgroundLoaded(false),
                                          loadLevel(fun),
                                          mainCamera(nullptr){}

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
    needReload = true;
}

GameObject &Scene::createGameObject() {
    gameObjects.push_front(GameObject(info));
    return gameObjects.front();
}

void Scene::startGameLoop() {
    while (info.getWindow().isOpen()) {
        sf::Event event{};
        while (info.getWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                info.getWindow().close();
        }
        if (needReload) {
            gameObjects.clear();
            loadLevel();
            needReload = false;
        }
        info.getWindow().clear(sf::Color::Blue);
        if (backgroundLoaded)
            info.getWindow().draw(background);
        this->update();
        this->draw();
        this->info.onFrameDone();
        cleaner.afterUpdate();
        info.getWindow().display();
    }
}

void Scene::setBackground(sf::Texture &backgroundTexture) {
    background.setTexture(backgroundTexture, false);
    background.setScale(info.screenW / static_cast<float>(backgroundTexture.getSize().x),
                        info.screenH / static_cast<float>(backgroundTexture.getSize().y));
    backgroundLoaded = true;
}

const GlobalInfo &Scene::getInfo() const {
    return info;
}