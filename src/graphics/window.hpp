#pragma once

#include "graphics/graphics.hpp"
#include "utils/utils.hpp"

namespace lorentz
{

    struct Window {
        // TODO(rene) http://clarkkromenaker.com/post/gengine-03-game-loop/
        GLFWwindow *handle;

        void setup(const char *application_name, i32 width, i32 height);
        bool running();
        void update();
        void destroy();
    };

}; // namespace lorentz
