#ifndef BUBBLYENGINE_SCENE_H
#define BUBBLYENGINE_SCENE_H


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include "GlobalInfo.h"
#include "GameObject.h"
#include "CollisionManager.h"
#include "CleanManager.h"
#include "CameraComponent.h"
#include <functional>

class Scene {
private:
    GlobalInfo info;

    void update();

    void draw();

    std::forward_list<GameObject> gameObjects;
    CleanManager cleaner;
    bool needReload;
    sf::Sprite background;
    bool backgroundLoaded;
    std::function<void()> loadLevel;
    CameraComponent* mainCamera;
public:
    explicit Scene(std::function<void()>);

    void setBackground(sf::Texture &);

    void reload();

    void startGameLoop();

    GameObject &createGameObject();

    const GlobalInfo &getInfo() const;
};


#endif //SHOOTINGGALLERY_GAMEFIELD_H
