
#include "headers/Window.hpp"

MousePos Window::mousePos = {0.0, 0.0, 0.0, 0.0, false};

void mouse_callback(GLFWwindow *window, double xpos, double ypos)
{
    Window::mousePos.px = Window::mousePos.x;
    Window::mousePos.py = Window::mousePos.y;
    Window::mousePos.x = xpos;
    Window::mousePos.y = ypos;

    Window::mousePos.moved = true;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}