#include "Collider.h"

namespace Bubbly {
    Collider Collider::circleCollider(float radius) {
        Collider result;
        result.type = CIRCLE;
        result.properties = radius;
        return result;
    }

    Collider Collider::rectangleCollider(glm::vec2 size) {
        Collider result;
        result.type = RECTANGLE;
        result.properties = size;
        return result;
    }

    ColliderType Collider::getType() {
        return type;
    }

    float Collider::getRadius() {
        return std::get<float>(properties);
    }

    glm::vec2 Collider::getSize() {
        return std::get<glm::vec2>(properties);
    }
}