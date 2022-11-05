#pragma once

#include "graphics/graphics.hpp"
#include "utils/utils.hpp"

namespace lorentz
{
    /*
     * @brief:  Window manager handles the window and keyboard events. It
     *          has GLFW as a dependency. Note GLFW is a C library with C++
     *          wrapper.
     */
    struct Window {
        /*
         * @brief:  Window handler
         */
        GLFWwindow *handle;

        /*
         * @brief:  Window manager handles the window and keyboard events. It
         * @params: - application_name[in]: Is the name on the title bar of the
         *            window
         *          - width[in]: is the width of the window in pixels.
         *          - height[in]: is the height of the window in pixels.
         * @return: (void)
         */
        void setup(const char *application_name, i32 width, i32 height);

        /*
         * @brief:  Checks if the window should continue to run or not.
         * @return: (bool) false if the users exits the program, true to
         *          continue.
         * @return: (void)
         */
        bool running();

        /*
         * @brief:  Window manager handles the window and keyboard events. It
         * @TODO:   Add timestep functionality, reference:
         *            - http://clarkkromenaker.com/post/gengine-03-game-loop/
         * @return: (void)
         */
        void update();

        /*
         * @brief:  Frees up all allocated memory from the window manager.
         * @return: (void)
         */
        void destroy();
    };

}; // namespace lorentz
