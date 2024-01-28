#include "window.h"
#include "GLFW/glfw3.h"

#include <iostream>
#include <memory>

void Window::begin(std::shared_ptr<Renderer> renderer) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(_x, _y, _title, NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to initialize GLFW" << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }

    glViewport(0, 0, _x, _y);
    glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    });

    _renderer = renderer;

    while (!glfwWindowShouldClose(window)) {
        _renderer->run();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Window::end() {
    glfwTerminate();
}
