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

    void run();

};