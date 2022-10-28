#include "graphics/window.hpp"
#include "GLFW/glfw3.h"
#include "lorentz.hpp"

namespace lorentz::graphics
{
    void Window::create(const char* application_name)
    {
        glfwInit();

        this->handle = glfwCreateWindow(
            width, height, application_name, nullptr, nullptr);

        glfwMakeContextCurrent(this->handle);
    }

    bool Window::running()
    {
        return glfwWindowShouldClose(this->handle) ? false : true;
    }

    void Window::destroy()
    {
        glfwTerminate();
    }
};
