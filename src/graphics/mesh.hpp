#pragma once

#include "math/math.hpp"
#include "utils/utils.hpp"

namespace lorentz::graphics
{
    /* File private */
        typedef u32 vbo_t, vao_t;

        struct VBO
        {
            vbo_t handle;

            VBO();
            
            void bind();
            void destroy();
        };

        struct VAO 
        {
            vao_t handle;

            VAO();

            void bind();
            void destroy();
        };

    struct Mesh
    {
        std::vector<glm::vec3> vertices;
        std::vector<u32> triangles;

        VBO vbo;
        VAO vao;

        Mesh(std::vector<glm::vec3> vertices)
            : vertices(vertices) { create(); }

        void use();

        void destroy();

      private: 

        void create();

    };
    
} // namespace lorentz::graphics
