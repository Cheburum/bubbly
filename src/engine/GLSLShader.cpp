#include "GLSLShader.h"
#include "helpFunctions.h"
#include <fstream>

namespace Bubbly {
    GLSLShader::GLSLShader() {
        compiled = 0;
        shader = 0;
    }

    bool GLSLShader::loadShader(ShaderType type, std::string_view filename) {
        //delete shader if it already exists
        if (compiled) {
            compiled = 0;
            shader = 0;
            glDeleteShader(shader);
        }
        //loading source
        std::ifstream file(filename.data());
        const std::string source{std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};
        const auto c_str = source.c_str();
        shader = glCreateShader(type);
        if (shader == 0) {
            return false;
        }
        glShaderSource(shader, 1, &c_str, nullptr);
        glCompileShader(shader);

        //error check
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
        if (!compiled) {
            printGLerrors(shader, glGetShaderiv, glGetShaderInfoLog);
            glDeleteShader(shader);
            return false;
        }
        return true;
    }

    GLSLShader::GLSLShader(ShaderType type, std::string_view filename) {
        loadShader(type, filename);
    }

    bool GLSLShader::isCompiled() const {
        return compiled != 0;
    }

    GLuint GLSLShader::getShaderId() const {
        return shader;
    }
}
