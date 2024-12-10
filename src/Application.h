#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

class Application {
public:
    Application();
    ~Application();

    bool Update();

private:
    GLFWwindow* window;

    static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
};
