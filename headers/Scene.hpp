#pragma once

#include "InputMap.hpp"
#include "Camera.hpp"
#include "VAO.hpp"
#include "PlaneMesh.hpp"

class Scene
{
private:
    Camera camera;
    PlaneMesh hug;
    Shader mainShader;

public:
    Scene() : hug({{-0.5f,  0.5f, 2.0f},
                   { 0.5f,  0.5f, 2.0f},
                   { 0.5f, -0.5f, 2.0f},
                   {-0.5f, -0.5f, 2.0f}},
                   "../assets/hug.png"),
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

    void render()
    {
        mainShader.setMat4("proj", camera.getProjMatrix());
        mainShader.setMat4("view", camera.getViewMatrix());
        hug.draw(mainShader);

        // camera.__debugPrint();
    }
};