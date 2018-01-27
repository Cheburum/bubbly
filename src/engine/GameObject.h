#ifndef BUBBLYENGINE_GAMEOBJECT_H
#define BUBBLYENGINE_GAMEOBJECT_H


#include <forward_list>
#include <map>
#include <memory>
#include "Transform.h"

namespace Bubbly {
    class Component;

    class GlobalInfo;

    class GameObject {
    private:
        Transform transform;
        std::map <std::string, std::shared_ptr<Component>> components;
        bool destroyed;
        GlobalInfo &info;
    public:
        explicit GameObject(GlobalInfo &gameWorld1);

        GameObject(const GameObject &other);

        GameObject(const GameObject &&other);

        GameObject &operator=(const GameObject &other);

        GameObject &operator=(const GameObject &&other);

        void update();

        void draw();

        void addComponent(const std::string &, std::shared_ptr <Component> comp);

        void addComponent(const std::string &, Component *raw);

        GlobalInfo &getWorldInfo();

        bool containsComponent(const std::string &) const;

        bool isDestroyed() const;

        void destroy();

        template<class T>
        std::weak_ptr <T> getComponent(const std::string &name) {
            return std::dynamic_pointer_cast<T>(components[name]);
        }

        Transform &getTransform();
    };
}


#endif