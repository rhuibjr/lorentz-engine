#include "utils/utils.hpp"

#include "graphics/graphics.hpp"
#include "graphics/texture.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace lorentz::graphics
{

#define LRTZ_TEXTURE_DESIRED_CHANNELS 0

    /* Texture */
    Texture::Texture(const std::string texture_path)
    {
        this->texture_raw_data = stbi_load(
            (const char *)texture_path.c_str(), &texture_data.width,
            &texture_data.width, &texture_data.channels,
            LRTZ_TEXTURE_DESIRED_CHANNELS);

        if (!this->texture_raw_data)
            log(ERROR, TAG_TEXTURE, "Unable to load the texture: %s",
                texture_path.c_str());

        this->create();
    }

    Texture::~Texture() { this->destroy(); }

#define LRTZ_TEXTURE_GENERATE_AMOUNT 1
#define LRTZ_TEXTURE_LEVEL_OF_DETAIL 0

    void Texture::create()
    {
        glGenTextures(LRTZ_TEXTURE_GENERATE_AMOUNT, &this->texture);
        glBindTexture(GL_TEXTURE_2D, this->texture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(
            GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(
            GL_TEXTURE_2D, LRTZ_TEXTURE_LEVEL_OF_DETAIL, GL_RGB,
            this->texture_data.width, this->texture_data.height, 0, // Must stay zero
            GL_RGB, GL_UNSIGNED_BYTE, this->texture_raw_data);

        glGenerateMipmap(GL_TEXTURE_2D);

        stbi_image_free(this->texture_raw_data);
    }

    void Texture::destroy()
    {
        glDeleteTextures(LRTZ_TEXTURE_GENERATE_AMOUNT, &this->texture);
    }

    void Texture::use() { glBindTexture(GL_TEXTURE_2D, this->texture); }

}; // namespace lorentz::graphics
