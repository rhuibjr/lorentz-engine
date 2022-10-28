#pragma once

#include "graphics/graphics.hpp"
#include "types.hpp"

namespace lorentz::graphics
{
    struct Window
    {
        i32 width = 1024;
        i32 height = 720;

        GLFWwindow* handle;

        void create(const char* application_name);
        bool running();
        void update();
        void destroy();
    };
};
