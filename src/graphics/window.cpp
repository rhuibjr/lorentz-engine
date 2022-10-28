#include "graphics/window.hpp"
#include "lorentz.hpp"
#include "types.hpp"

namespace lorentz::graphics
{
    void Window::create(const char* application_name)
    {
        if (!glfwInit())
            LORENTZ_EXIT_ON_ERROR("Error initializing GLFW3");

        this->handle = glfwCreateWindow(
            width, height, application_name, nullptr, nullptr);

        if (!this->handle)
            LORENTZ_EXIT_ON_ERROR("Error creating GLFW3 window");

        glfwMakeContextCurrent(this->handle);
    }

    void Window::update()
    {
        glfwSwapBuffers(this->handle);
        glfwPollEvents();
    }

    bool Window::running()
    {
        return glfwWindowShouldClose(this->handle) ? false : true ;
    }

    void Window::destroy()
    {
        glfwTerminate();
    }
};
