#pragma once

#include "InputMap.hpp"

#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include "libs/glad/include/glad/gl.h"

void framebuffer_size_callback(GLFWwindow *window, int width, int height);

void mouse_callback(GLFWwindow *window, double xpos, double ypos);

class Window
{
private:
    GLFWwindow* window = nullptr;

public:
    static MousePos mousePos;
    
    InputMap processInput() const;

    void pollEvents() const
    {
        glfwPollEvents();
    }

    void swapBuffers() const
    {
        glfwSwapBuffers(window);
    }

    bool shouldClose() const
    {
        return glfwWindowShouldClose(window);
    }

    double getTime() const
    {
        return glfwGetTime();
    }

    Window(const char* title, int width = 800, int height = 600);

    ~Window()
    {
        glfwTerminate();
    }

    void clear() const
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }

};