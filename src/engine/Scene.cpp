#include <fstream>
#include <sstream>
#include <iostream>
#include "Scene.h"
#include "PhysComponent.h"

namespace Bubbly {
    Scene::Scene(std::function<void()> fun) : cleaner(gameObjects),
                                              needReload(true),
                                              info(*this),
                                              backgroundLoaded(false),
                                              loadLevel(fun),
                                              mainCamera(nullptr) {}

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
        testShader.loadFragmentVertex("../shaders/fragment_shader.frag", "../shaders/vertex_shader.vert");
        testShader.link();
        while (!info.getWindow().shouldClose()) {
            if (needReload) {
                gameObjects.clear();
                loadLevel();
                needReload = false;
            }
            info.getWindow().clear();
            if (backgroundLoaded) {
                //TODO    info.getWindow().draw(background);
            }
            this->update();
            this->draw();
            this->info.onFrameDone();
            cleaner.afterUpdate();
            info.getWindow().display();
        }
    }

    void Scene::setBackground(Texture &backgroundTexture) {
        //   background.setTexture(backgroundTexture, false);
        //  background.setScale(info.screenW / static_cast<float>(backgroundTexture.getSize().x),
        //                       info.screenH / static_cast<float>(backgroundTexture.getSize().y));
        backgroundLoaded = true;
    }

    const GlobalInfo &Scene::getInfo() const {
        return info;
    }
}