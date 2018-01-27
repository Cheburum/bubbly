#include <glm/vec2.hpp>
#include <GL/glew.h>
#include "Texture.h"
#include <stdexcept>

#define  STB_IMAGE_IMPLEMENTATION

#include "stb/stb_image.h"

namespace Bubbly {
    Texture::Texture() : loaded(false) {
        //TODO
    }

    Texture::Texture(const std::string &) {}

    glm::vec2 Texture::getSize() const {
        return glm::vec2(1, 1);
    }

    void Texture::bind() const {
        if (loaded)
            glBindTexture(GL_TEXTURE_2D, textureId);
        else
            throw std::runtime_error("Can not bind texture because it is not loaded!");
    }

    bool Texture::loadFromFile(std::string_view filename) {
        if (loaded) {
            glDeleteTextures(1, &textureId);
        }
        const auto image = stbi_load(filename.data(), &w, &h, &channels, STBI_rgb_alpha);
        glGenTextures(1, &textureId);
        glBindTexture(GL_TEXTURE_2D, textureId);
        if (channels = 3)
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
        else if (channels = 4)
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        stbi_image_free(image);
        loaded = true;
        return true;
    }
}