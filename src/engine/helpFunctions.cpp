#include "helpFunctions.h"

namespace Bubbly {
    void printGLerrors(GLuint object,
                       const std::function<void(GLuint, GLenum, GLint *)> &iv,
                       const std::function<void(GLuint, GLsizei, GLsizei *, GLchar *)> &logFunc) {
        GLint infoLen = 0;
        iv(object, GL_INFO_LOG_LENGTH, &infoLen);
        if (infoLen > 1) {
            std::vector<char> infoLog(static_cast<unsigned long>(infoLen));
            logFunc(object, infoLen, NULL, &infoLog[0]);
            std::cerr << "Error compiling shader:" << &infoLog[0] << std::endl;
        }
    }
}