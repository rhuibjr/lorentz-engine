/* Copyright (C) 2022 René Huiberts - All Rights Reserved */

/* Lorentz platform dependencies */
#include "graphics/window.hpp"
#include "utils/clock.hpp"

/* Lorentz platform */
#include "lorentz.hpp"

#include "graphics/mesh.hpp"
#include "graphics/program.hpp"

namespace lorentz
{
    Platform platform;

    void initialize()
    {
        /* Declaration of platform */
        platform.clock = new Clock();
        platform.window = new Window();

        log(INFO, TAG_PLATFORM, "Initializing Lorentz"); // Uses platform.clock

        /* Setting up platform components */
        platform.window->setup("A Lorentz application", 1024, 720);
    }

    void render()
    {
        log(INFO, TAG_PLATFORM, "Starting the Renderer");

        graphics::Mesh triangle(
            {{-0.5f, -0.5f, 0.0f},
             {0.5f, -0.5f, 0.0f},
             {0.0f, 0.5f, 0.0f}});

        graphics::Program shader({
            "./resources/shaders/vertex_shaders/vertex_shader.glsl",
            "./resources/shaders/fragment_shaders/fragment_shader.glsl"
        });

        UNUSED f32 time = 0.0, accumulator = 0.0, fixed_delta_time = 0.1;
        uint16_t frames = 0;

        f32 old_time = glfwGetTime();

        while (platform.window->running()) {
            f32 now = glfwGetTime();
            f32 frame_time = now - old_time;
            old_time = now;

            accumulator += frame_time;

            while(accumulator >= fixed_delta_time)
            {
                accumulator -= fixed_delta_time;
                time += fixed_delta_time;
                
                frames++;
            }

            glClearColor(LORENTZ_CLEAR_COLOUR);
            glClear(GL_COLOR_BUFFER_BIT);

            shader.use();
            triangle.use();

            platform.window->update(frames);
            frames = 0;

        }
    }

    void destroy()
    {
        log(INFO, TAG_PLATFORM, "Destroying the Renderer");
        platform.window->destroy();
    }

}; // namespace lorentz

int main(UNUSED int argc, UNUSED char *argv[])
{
    lorentz::initialize();
#if !BEAR
    lorentz::render();
#endif
    lorentz::destroy();
}
