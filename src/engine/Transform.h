#ifndef BUBBLYENGINE_TRANSFORM_H
#define BUBBLYENGINE_TRANSFORM_H

#include <glm/vec2.hpp>

namespace Bubbly {
    class Transform {
    public:
        glm::vec2 position;
        float rotation;
        glm::vec2 scale;

        Transform();
    };
}

#endif
