#pragma once

#include "VAO.hpp"
#include "Window.hpp"

class App
{
private:
    Window window;
    VAO triangle;
    Shader mainShader;

public:

    App(const char* title, int winWidth = 800, int winHeight = 600):
        window(title, winWidth, winHeight),
        triangle({{-0.5f, -0.5f, 0.0f},
                  { 0.5f, -0.5f, 0.0f},
                  { 0.0f,  0.5f, 0.0f}}),
        mainShader("../shaders/vertex.glsl", "../shaders/fragment.glsl")
    {

    }

    void run() const
    {
        while(!window.shouldClose())
        {
            window.processInput();

            triangle.draw(mainShader);

            window.pollEvents();
            window.swapBuffers();
        }
    }
};