#pragma once

// #include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <iostream>

const glm::vec3 ABSOLUTE_UP(0.0f, 1.0f, 0.0f);

class Camera
{
private:
    glm::vec3 position;
    glm::vec3 cameraUp;
    glm::vec3 cameraRight;
    glm::vec3 cameraDir;

    float yaw = 0.0f;
    float pitch = 0.0f;

    glm::mat4 viewMatrix;
    glm::mat4 projMatrix;

    float fov = 70.0f;
    float aspect = 1.0f;
    float nearPlane = 0.1f;
    float farPlane = 100.0f;

    float speed = 1.0f;
    float mouseSens = 0.15f;
public:
    Camera():
        position(0.0f, 0.0f, 0.0f),
        cameraUp(0.0f, 1.0f, 0.0f),
        cameraDir(0.0f, 0.0f, 1.0f),
        cameraRight(1.0f, 0.0f, 0.0f)
    {
        viewMatrix = glm::lookAt(position, position + cameraDir, cameraUp);
        projMatrix = glm::perspective(glm::radians(fov), aspect, nearPlane, farPlane);
    }

    void recalculateViewMatrix()
    {
        viewMatrix = glm::lookAt(position, position + cameraDir, cameraUp);
    }

    void translateBy(const glm::vec3& v)
    {
        position += v;
    }

    void flyForward(float deltaTime)
    {
        position += deltaTime * speed * cameraDir;
    }

    void flyRight(float deltaTime)
    {
        position += deltaTime * speed * cameraRight;
    }

    glm::mat4 getProjMatrix() const
    {
        return projMatrix;
    }

    glm::mat4 getViewMatrix() const
    {
        return viewMatrix;
    }

    void __debugPrint() const
    {
        std::cout << "Position: " << position.x << ' ' << position.y << ' ' << position.z << '\n';
        std::cout << "Direction: " << cameraDir.x << ' ' << cameraDir.y << ' ' << cameraDir.z << '\n';
    }

private:
    // recalculate orientation vectors according to pitch and yaw
    void recalculateOrientation();

public:
    void moveDir(float dPitch, float dYaw);

};