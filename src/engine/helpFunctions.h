#ifndef BUBBLYENGINE_HELPFUNCTIONS_H
#define BUBBLYENGINE_HELPFUNCTIONS_H

#include <glm/vec2.hpp>
#include <GL/glew.h>
#include <functional>
#include <iostream>

namespace Bubbly {
    template<typename T>
    glm::tvec2<T> multiByElement(glm::tvec2<T> &a, glm::tvec2<T> &b) {
        return glm::tvec2<T>(a.x * b.x, a.y * b.y);
    }

    void printGLerrors(GLuint object,
                       const std::function<void(GLuint, GLenum, GLint *)> &iv,
                       const std::function<void(GLuint, GLsizei, GLsizei *, GLchar *)> &logFunc);
}
#endif
