#ifndef BUBBLY_HELPFUNCTIONS_H
#define BUBBLY_HELPFUNCTIONS_H

#include <glm/vec2.hpp>

namespace Bubbly {
    template<typename T>
    glm::tvec2 <T> multiByElement(glm::tvec2 &a, glm::tvec2 <T> &b) {
        return glm::tvec2<T>(a.x * b.x, a.y * b.y);
    }
}
#endif
