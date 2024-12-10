#include "Application.h"

#include <stdexcept>
#include <iostream>
#include <glad/glad.h>

Application::Application() {
    if (!glfwInit()) {
        throw std::runtime_error("Unable to initialize GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(1920, 1080, "Particles", nullptr, nullptr);
    if(!window) {
        glfwTerminate();
        throw std::runtime_error("Unable to create window");
    }

    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        throw std::runtime_error("Unable to initialize OpenGL");
    }

    glViewport(0, 0, 1920, 1080);
    glfwSetFramebufferSizeCallback(window, Application::FramebufferSizeCallback);
}

Application::~Application() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

bool Application::Update() {
    if(!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1, 0, 1, 1);

        glfwSwapBuffers(window);
        glfwPollEvents();
        return true;
    }
    return false;
}

void Application::FramebufferSizeCallback(GLFWwindow* window, int width, int height) {
    std::cout << "test\n";
    glViewport(0, 0, width, height);
}
