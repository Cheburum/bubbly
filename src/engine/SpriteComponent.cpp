#include "SpriteComponent.h"
#include "GameObject.h"
#include "GlobalInfo.h"

namespace Bubbly {
    glm::vec2 SpriteComponent::getScaleToUnits(glm::vec2 units) const {
        const auto pixelsPerUnit = gameObject.getWorldInfo().getPixelsPerUnit();
        return glm::vec2(pixelsPerUnit / textureSize.x * units.x,
                         pixelsPerUnit / textureSize.y * units.y);
    }

    SpriteComponent::SpriteComponent(GameObject &gameObject1, const Texture &texture)
            : Component(gameObject1), texture(texture) {
        textureSize = texture.getSize();
        //sprite.setPosition(gameObject1.getTransform().position);
        //sprite.setRotation(gameObject1.getTransform().rotation);
        //sprite.setScale(getScaleToUnits(gameObject.getTransform().scale));
    }

    void SpriteComponent::update() {

    }

    void SpriteComponent::draw() {
        const auto pixelsPerUnit = gameObject.getWorldInfo().getPixelsPerUnit();
        //sprite.setPosition(gameObject.getTransform().position * pixelsPerUnit);
        //sprite.setRotation(gameObject.getTransform().rotation);
        //sprite.setScale(getScaleToUnits(gameObject.getTransform().scale));
        //gameObject.getWorldInfo().getWindow().draw(sprite);
    }
}