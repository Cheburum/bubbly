#ifndef BUBBLYENGINE_SCENE_H
#define BUBBLYENGINE_SCENE_H

#include "GlobalInfo.h"
#include "GameObject.h"
#include "CollisionManager.h"
#include "CleanManager.h"
#include "CameraComponent.h"
#include <functional>
#include "Texture.h"

namespace Bubbly {

    class Scene {
    private:
        GlobalInfo info;

        void update();

        void draw();

        std::forward_list <GameObject> gameObjects;
        CleanManager cleaner;
        bool needReload;
        //sf::Sprite background;
        bool backgroundLoaded;
        std::function<void()> loadLevel;
        CameraComponent *mainCamera;
    public:
        explicit Scene(std::function<void()>);

        void setBackground(Texture &);

        void reload();

        void startGameLoop();

        GameObject &createGameObject();

        const GlobalInfo &getInfo() const;
    };

}
#endif
