#ifndef BUBBLYENGINE_COLLIDER_H
#define BUBBLYENGINE_COLLIDER_H

#include <vector>
#include <glm/vec2.hpp>
#include <variant>

namespace Bubbly {
    enum ColliderType {
        CIRCLE,
        RECTANGLE
    };

//Abstract collider
    class Collider {
    private:
        ColliderType type;
        std::variant<float, glm::vec2> properties;
    public:
        ColliderType getType();

        float getRadius();

        glm::vec2 getSize();

        static Collider circleCollider(float radius);

        static Collider rectangleCollider(glm::vec2 size);
    };
}

#endif
