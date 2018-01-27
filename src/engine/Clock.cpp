#include <GLFW/glfw3.h>
#include "Clock.h"

namespace Bubbly {
    Clock::Clock() {
        restart();
    }

    void Clock::restart() {
        start_time = glfwGetTime();
    }

    double Clock::getElapsedTime() const {
        return glfwGetTime() - start_time;
    }
}