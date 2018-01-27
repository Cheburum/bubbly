#ifndef BUBBLY_WINDOW_H
#define BUBBLY_WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string_view>

namespace Bubbly {
    class Window {
    private:
        GLFWwindow *window;

        static void GLFWErrorCallback(int, const char *);

    public:
        Window(unsigned int width = 800, unsigned int height = 600, std::string_view title = "Hello, world!");

        void setClearColor(float, float, float, float) const;

        void clear() const;

        void display() const;

        bool shouldClose() const;

        ~Window();
    };
}

#endif
