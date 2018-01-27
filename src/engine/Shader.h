//
// Created by cheburum on 26.01.18.
//

#ifndef BUBBLY_SHADER_H
#define BUBBLY_SHADER_H


#include <string_view>

namespace Bubbly {
    class GLSLShader {
    private:

    };

    class Shader {
    public:
        enum ShaderType {
            VERTEX_SHADER,
            FRAGMENT_SHADER
        };

        void loadShaderFromFile(ShaderType, std::string_view filename);

        void loadShaderFromSrc(ShaderType, std::string_view shaderSoure);
    };
}

#endif //BUBBLY_SHADER_H
