#include "graphics/window.hpp"

namespace lorentz {

void Window::setup(const char* application_name, i32 width, i32 height)
{
    if (!glfwInit())
        log(ERROR, TAG_WINDOW, "Initializing GLFW3");

    this->handle = glfwCreateWindow(width, height, application_name, nullptr, nullptr);

    if (!this->handle)
        log(ERROR, TAG_WINDOW, "Creating window");

    glfwMakeContextCurrent(this->handle);
    log(INFO, TAG_WINDOW, "Created window");
}

void Window::update()
{
    glfwSwapBuffers(this->handle);
    glfwPollEvents();
}

bool Window::running()
{
    return glfwWindowShouldClose(this->handle) ? false : true;
}

void Window::destroy()
{
    log(INFO, TAG_WINDOW, "Closing window");
    glfwTerminate();
}

}; // namespace lorentz
