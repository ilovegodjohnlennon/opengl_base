#pragma once

#include "InputMap.hpp"
#include "Camera.hpp"
#include "VAO.hpp"

class Scene
{
private:
    Camera camera;
    VAO triangle;
    Shader mainShader;

public:
    Scene() : triangle({{-0.5f, -0.5f, 2.0f},
                        {0.5f, -0.5f, 2.0f},
                        {0.0f, 0.5f, 2.0f}}),
              mainShader("../shaders/vertex.glsl", "../shaders/fragment.glsl")
    {

    }

    void update(const InputMap& inputMap, float deltaTime)
    {
        if(inputMap.forwards)
            camera.flyForward(deltaTime);
        if(inputMap.backwards)
            camera.flyForward(-deltaTime);
        if(inputMap.left)
            camera.flyRight(-deltaTime);
        if(inputMap.right)
            camera.flyRight(deltaTime);
        
        if(inputMap.mouseMoved)
            camera.moveDir(inputMap.mouseDy, inputMap.mouseDx);
        
        camera.recalculateViewMatrix();
    }

    void render() const
    {
        mainShader.setMat4("proj", camera.getProjMatrix());
        mainShader.setMat4("view", camera.getViewMatrix());
        triangle.draw(mainShader);

        // camera.__debugPrint();
    }
};