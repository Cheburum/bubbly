#ifndef BUBBLY_GLSLSHADER_H
#define BUBBLY_GLSLSHADER_H

#include <GL/glew.h>
#include <string_view>

namespace Bubbly {
    enum ShaderType {
        VERTEX_SHADER = GL_VERTEX_SHADER,
        FRAGMENT_SHADER = GL_FRAGMENT_SHADER
    };

    class GLSLShader {
    private:
        GLuint shader;
        GLint compiled;
    public:
        GLSLShader();

        GLSLShader(ShaderType, std::string_view);

        bool loadShader(ShaderType, std::string_view);

        bool isCompiled() const;

        GLuint getShaderId() const;
    };
}

#endif //BUBBLY_GLSLSHADER_H
