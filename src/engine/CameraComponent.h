#ifndef BUBBLY_CAMERACOMPONENT_H
#define BUBBLY_CAMERACOMPONENT_H


#include "GameObject.h"
#include "Component.h"

namespace Bubbly {
    class CameraComponent : public Component {
    private:
        bool isMain;
        //TODO sf::View sfmlView;
    public:
        explicit CameraComponent(GameObject &gameObject);

        void update();

        void setMain(bool);
    };
}

#endif
