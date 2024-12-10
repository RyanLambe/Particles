#include <iostream>

//#include <glad/gl.h>
#include <GLFW/glfw3.h>

int main() {
    std::cout << "Hello, World!" << std::endl;

    if (!glfwInit()) {
        // todo: error
    }

    GLFWwindow* window = glfwCreateWindow(1920, 1080, "Particles", nullptr, nullptr);
    if(!window) {
        // todo: error
    }

    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
