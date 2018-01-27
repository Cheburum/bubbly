#ifndef BUBBLY_SHADER_H
#define BUBBLY_SHADER_H

#include <memory>
#include "GLSLShader.h"

namespace Bubbly {

    class ShaderProgram {
    private:
        GLSLShader fragment, vertex;
        GLuint program;

        GLSLShader &getShaderByType(ShaderType);

        GLint linked;
    public:
        ShaderProgram();

        void loadShaderFromFile(ShaderType, std::string_view filename);

        void loadFragmentVertex(std::string_view fragment, std::string_view vertex);

        bool link();
    };
}

#endif //BUBBLY_SHADER_H
