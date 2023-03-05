#pragma once

#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include "libs/glad/include/glad/gl.h"

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}



class Window
{
private:
    GLFWwindow* window = nullptr;

public:
    void processInput() const
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }

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


    Window(const char* title, int width = 800, int height = 600)
    {
        if(glfwInit() != GLFW_TRUE)
        {
            throw "GLFW init error!";
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(width, height, title, NULL, NULL);
        if(!window)
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
    }

    ~Window()
    {
        glfwTerminate();
    }

};