#ifndef BUBBLY_TEXTURE_H
#define BUBBLY_TEXTURE_H

#include <string>
#include <GL/glew.h>

namespace Bubbly {
//TODO
    class Texture {
    private:
        bool loaded;
        GLuint textureId;
        int w, h, channels;
    public:
        Texture();

        bool loadFromFile(std::string_view);

        Texture(const std::string &);

        glm::vec2 getSize() const;

        void bind() const;
    };
}

#endif
