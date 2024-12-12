#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "imgui.h"

class Application {
public:
    Application();
    ~Application();

    bool Update();
    void RenderImGui();

private:
    GLFWwindow* window;

    void SetupGLFW();
    void SetupImGui();

    static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
};
