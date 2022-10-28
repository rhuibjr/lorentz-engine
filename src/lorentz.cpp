#include "lorentz.hpp"
#include "GLFW/glfw3.h"
#include "graphics/graphics.hpp"

namespace lorentz
{
    Platform platform;

    void initialize()
    {
        platform.window = new Window();
        platform.window->create("A Lorentz application");
    }

    void render()
    {
        // TODO(rene) empty this while loop from opengl functions.
        while(platform.window->running())
        {
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(platform.window->handle);

            glfwPollEvents();
        }
    }

    void destroy()
    {
        platform.window->destroy();
    }
};

int main(UNUSED int argc, UNUSED char *argv[])
{
    lorentz::initialize();
    lorentz::render();

    lorentz::destroy();
}
