#include "graphics/window.hpp"

namespace lorentz
{
    void Window::setup(const char *application_name, i32 width, i32 height)
    {
        if (!glfwInit())
            log(ERROR, TAG_WINDOW, "Initializing GLFW3");

#if SYS_DARWIN
        glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

        this->handle =
            glfwCreateWindow(width, height, application_name, nullptr, nullptr);

        if (!this->handle)
            log(ERROR, TAG_WINDOW, "Creating window");

        glfwMakeContextCurrent(this->handle);
        gladLoadGL(); // Call before using GL functions

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
