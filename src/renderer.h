#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Renderer {
public:
    virtual void run() const = 0;
};
