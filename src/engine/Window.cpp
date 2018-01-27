#include "Window.h"
#include <stdexcept>
#include <iostream>

namespace Bubbly {
    void Window::GLFWErrorCallback(int error, const char *description) {
        std::cerr << "Error " << error << ": " << description << std::endl;
    }

    void Window::setClearColor(float r, float g, float b, float a) const {
        glClearColor(r, g, b, a);
    }

    void Window::clear() const {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Window::display() const {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    bool Window::shouldClose() const {
        return glfwWindowShouldClose(window);
    }

    Window::Window(unsigned int width, unsigned int height, std::string_view title) {
        if (!glfwInit())
            throw std::runtime_error("GLFW can not be inited");
        glfwSetErrorCallback(GLFWErrorCallback);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        window = glfwCreateWindow(width, height, title.data(), NULL, NULL);
        if (!window)
            throw std::runtime_error("Window not created");
        glfwMakeContextCurrent(window);
        glewInit();
        setClearColor(1, 1, 1, 1);
        clear();
        display();
    }

    Window::~Window() {
        glfwTerminate();
    }
}