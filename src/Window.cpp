#include "Window.hpp"

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

InputMap Window::processInput() const
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    InputMap inputMap;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        inputMap.forwards = true;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        inputMap.backwards = true;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        inputMap.left = true;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        inputMap.right = true;

    if (mousePos.moved)
    {
        inputMap.mouseDx = -mousePos.x + mousePos.px;
        inputMap.mouseDy = -mousePos.y + mousePos.py;
        inputMap.mouseMoved = true;
        mousePos.moved = false;
    }
    else
    {
        inputMap.mouseMoved = false;
        inputMap.mouseDx = 0.0f;
        inputMap.mouseDy = 0.0f;
    }
    return inputMap;
}

Window::Window(const char *title, int width, int height)
{
    if (glfwInit() != GLFW_TRUE)
    {
        throw "GLFW init error!";
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window)
    {
        throw "Window creation error!";
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGL(glfwGetProcAddress))
    {
        throw "Failed to initialize glad!";
    }

    glViewport(0, 0, 800, 600);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(window, mouse_callback);
}
