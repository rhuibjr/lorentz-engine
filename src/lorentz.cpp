#include "utils/clock.hpp"
#include "utils/utils.hpp"

#include "graphics/window.hpp"

#include "lorentz.hpp"
#include "platform.hpp"

namespace lorentz {

Platform platform;

void initialize()
{
    /* Declaration of platform */
    platform.clock = new Clock();
    platform.window = new Window();

    /* Setting up platform components*/
    platform.window->setup("A Lorentz application", 1024, 720);

    log(INFO, TAG_PLATFORM, "Initializing Lorentz");
}

void render()
{
    log(INFO, TAG_PLATFORM, "Starting the Renderer");

    while (platform.window->running()) {
        glClearColor(LORENTZ_CLEAR_COLOUR);
        glClear(GL_COLOR_BUFFER_BIT);

        platform.window->update();
    }
}

void destroy()
{
    log(INFO, TAG_PLATFORM, "Destroying the Renderer");

    platform.window->destroy();
    delete platform.window;
    delete platform.clock;
}

}; // namespace lorentz

int main(UNUSED int argc, UNUSED char* argv[])
{
    lorentz::initialize();
    lorentz::render();

    lorentz::destroy();
}
