#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Renderer {
public:
    inline virtual void run() const = 0;
};
