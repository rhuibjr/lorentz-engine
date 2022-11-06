#pragma once

#include "utils/utils.hpp"

namespace lorentz::graphics
{
    /* File private */
    namespace
    {
        /*
         * @brief: Texture type, synonym of the dreades GLuint type.
         */
        typedef u32 texture_t;
        /*
         * @brief: Texture type, for the image loaders output.
         */
        typedef u8 texture_raw_data_t;
        /*
         * @brief: Texture type, to hold image data.
         */
        typedef struct texture_data {
            i32 width, height, channels;
        } texture_data;

    } // namespace

    /*
     * @brief: Texture container can create a texture from an image, and holds
     *         its composition and data.
     */
    struct Texture {
        /*
         * @brief: Hold the texture created from the image.
         */
        texture_t texture;

        /*
         * @brief: Hold the raw data from the image loader.
         */
        texture_raw_data_t *texture_raw_data;

        /*
         * @brief: Holds data for the image composition.
         */
        texture_data texture_data;

        /*
         * @brief:  Create texture object.
         * @params: - texture_path[in]: Relative path to the texture.
         */
        Texture(const std::string texture_path);

        /*
         * @brief: Calls the destroy function.
         */
        ~Texture();

        /*
         * @brief: Use the texture program in the current rendering state.
         * @return: (void)
         */
        void use();

        /*
         * @brief: Frees all allocated memory of the texture container.
         * @return: (void)
         */
        void destroy();

      private:
        /*
         * @brief:  Generates a texture from the image.
         * @return: (void)
         */
        void create();
    };

}; // namespace lorentz::graphics
