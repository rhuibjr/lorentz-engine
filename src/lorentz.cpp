#include "graphics/graphics.hpp"
#include "lorentz.hpp"
#include "types.hpp"

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
        while(platform.window->running())
        {
            glClearColor(LORENTZ_CLEAR_COLOUR);
            glClear(GL_COLOR_BUFFER_BIT);

            platform.window->update();
        }
    }

    void destroy()
    {
        platform.window->destroy();
        delete platform.window; 
    }
};

int main(UNUSED int argc, UNUSED char *argv[])
{
    lorentz::initialize();
    lorentz::render();

    lorentz::destroy();
}
