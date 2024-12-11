#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "imgui.h"

class Application {
public:
    Application();
    ~Application();

    bool Update();

private:
    GLFWwindow* window;

    void SetupGLFW();
    void SetupImGui();

    void RenderImGui();

    static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
};
