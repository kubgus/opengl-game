#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "renderer.h"

#include <memory>

class Window {
public:
    Window(int x, int y, const char* title) : _x(x), _y(y), _title(title) {}

    void begin(std::shared_ptr<Renderer> renderer);
    void end();
private:
    int _x, _y;
    const char* _title;
    std::shared_ptr<Renderer> _renderer;
};
