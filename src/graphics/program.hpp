#pragma once

#include "utils/utils.hpp"

namespace lorentz::graphics
{
    /* File private */
    namespace
    {
        /*
         * @brief: Shader type, synonym of the dreades GLuint type.
         */
        typedef u32 shader_t;

        /*
         * @brief: Shader container can compile shaders from their relative
         * path.
         */
        struct Shader {
            /*
             * @brief:  Compiles a single shader of type [type] and returns it.
             * @params: - shader_path[in]: Relative path to the shader.
             *          - type[in] Shader type, either vertex or fragment.
             * @TODO:   Add shader uniforms.
             * @return: (u32) Shader binary
             */
            static shader_t compile(std::string shader_path, u32 type);
        };

    } // namespace

    /*
     * @brief: Program container which holds a vertex and a fragment shader,
     * links them and controls their livespan.
     */
    struct Program {
        /*
         * @brief: Program made out of vertex shader and program shader.
         */
        u32 program;

        /*
         * @brief: Vertex shaders binary
         */
        shader_t vertex_shader;

        /*
         * @brief: Fragment shaders binary
         */
        shader_t fragment_shader;

        /*
         * @brief:  Compiles the two shaders given, and calls the create()
         * function.
         * @params: - shaders[2][in]: First item leads to the vertex shader
         * path, second items leads to fragment shader path.
         * @return: (void)
         */
        Program(std::array<std::string, 2> shaders);

        /*
         * @brief: Calls the destroy function.
         */
        ~Program();

        /*
         * @brief:  Use the shader program in the current rendering state.
         * @return: (void)
         */
        void use();

        /*
         * @brief: Frees all allocated memory of the program container.
         * @return: (void)
         */
        void destroy();

      private:
        /*
         * @brief:  Uses the two compiled shaders and links them together in a
         *          shader program.
         * @return: (void)
         */
        void create();
    };

} // namespace lorentz::graphics
