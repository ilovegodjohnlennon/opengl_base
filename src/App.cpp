
#include "App.hpp"

void App::run()
{
    InputMap inputMap;
    float deltaTime;
    float lastTime = window.getTime();
    float currentTime;

    while (!window.shouldClose())
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