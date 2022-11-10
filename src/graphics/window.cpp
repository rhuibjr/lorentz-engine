#include "graphics/window.hpp"

namespace lorentz
{
    void Window::setup(const std::string application_name, i32 width, i32 height)
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

        this->title = application_name;

        this->handle =
            glfwCreateWindow(width, height, this->title.c_str(), nullptr, nullptr);

        if (!this->handle)
            log(ERROR, TAG_WINDOW, "Creating window");

        glfwMakeContextCurrent(this->handle);
        gladLoadGL(); // Call before using GL functions

        log(INFO, TAG_WINDOW, "Created window");
    }

    void Window::update(uint16_t fps)
    {
        std::string new_title = "[FPS:  ] ";
        new_title.replace(6, 1, std::to_string(fps)).append(this->title);
        
        glfwSetWindowTitle(this->handle, new_title.c_str());
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
