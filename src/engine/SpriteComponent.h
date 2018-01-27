#ifndef BUBBLYENGINE_SPRITECOMPONENT_H
#define BUBBLYENGINE_SPRITECOMPONENT_H


#include "Component.h"
#include "Texture.h"

namespace Bubbly {
    class SpriteComponent : public Component {
    private:
        //sf::Sprite sprite;
        //float pixelsPerUnit;
        glm::vec2 textureSize;

        glm::vec2 getScaleToUnits(glm::vec2 units) const;

        const Texture &texture;
    public:
        SpriteComponent(GameObject &transform, const Texture &texture);

        void update();

        void draw();
    };
}

#endif
