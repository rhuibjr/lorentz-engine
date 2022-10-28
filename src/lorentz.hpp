#pragma once

#include "graphics/window.hpp"

namespace lorentz
{
    using graphics::Window;

    struct Platform
    {
        Window* window; 
    };

    void initialize();
    void render();
    void destroy();
};
