#include <stdexcept>
#include "ShaderProgram.h"
#include "helpFunctions.h"

namespace Bubbly {
    ShaderProgram::ShaderProgram() {
        if (!program)
            throw std::runtime_error("Can not create OpenGL program!");
    }

    GLSLShader &ShaderProgram::getShaderByType(ShaderType type) {
        switch (type) {
            case VERTEX_SHADER:
                return vertex;
            case FRAGMENT_SHADER:
                return fragment;
            default:
                throw std::runtime_error("No such type of shader in ShaderProgram");
        }
    }

    void ShaderProgram::loadShaderFromFile(ShaderType type, std::string_view filename) {
        auto neededShader = getShaderByType(type);
        if (!neededShader.loadShader(type, filename))
            throw std::runtime_error("Shader: " + std::string(filename) + " can not be compiled!");
    }

    void ShaderProgram::loadFragmentVertex(std::string_view fragmentSrc, std::string_view vertexSrc) {
        fragment.loadShader(FRAGMENT_SHADER, fragmentSrc);
        vertex.loadShader(VERTEX_SHADER, vertexSrc);
    }

    bool ShaderProgram::link() {
        if (linked) {
            glDeleteProgram(program);
        }
        program = glCreateProgram();
        glAttachShader(program, vertex.getShaderId());
        glAttachShader(program, fragment.getShaderId());
        glLinkProgram(program);
        glGetProgramiv(program, GL_LINK_STATUS, &linked);
        if (!linked) {
            printGLerrors(program, glGetProgramiv, glGetProgramInfoLog);
            glDeleteProgram(program);
        }
        return linked != 0;
    }
}