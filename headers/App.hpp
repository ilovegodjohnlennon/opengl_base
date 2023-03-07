#pragma once

#include "Window.hpp"
#include "Scene.hpp"
class App
{
private:
    Window window;
    Scene currentScene;

public:

    App(const char* title, int winWidth = 800, int winHeight = 600):
        window(title, winWidth, winHeight)
    {

    }

    void run()
    {
        InputMap inputMap;
        float deltaTime;
        float lastTime = window.getTime();
        float currentTime;

        while(!window.shouldClose())
        {
            currentTime = window.getTime();
            deltaTime = currentTime - lastTime;
            lastTime = currentTime;
            

            inputMap = window.processInput();

            currentScene.update(inputMap, deltaTime);

            window.clear();
            currentScene.render();

            window.pollEvents();
            window.swapBuffers();
        }
    }
};