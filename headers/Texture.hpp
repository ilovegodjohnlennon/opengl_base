#pragma once

#include "libs/glad/include/glad/gl.h"
#include "libs/stb_image/stb_image.h"

#include <string>

class Texture
{
private:
    GLuint id = 0;

public:
    Texture(const std::string& path)
    {
        int width;
        int height;
        int numberOfChannels;

        uint8_t* data = stbi_load(path.c_str(), &width, &height, &numberOfChannels, 0);
        if(!data)
        {
            std::string err("Could not load texture from ");
            err.append(path).append("\n");
            throw err.c_str();
        }

        glGenTextures(1, &id);
        glBindTexture(GL_TEXTURE_2D, id);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        stbi_image_free(data);
    }

    void bind() const
    {
        glBindTexture(GL_TEXTURE_2D, id);
    }
};