#include "Camera.hpp"

void Camera::recalculateOrientation()
{
    float p = glm::radians(pitch);
    float y = glm::radians(yaw);

    cameraDir.x = glm::cos(p) * glm::sin(y);
    cameraDir.y = glm::sin(p);
    cameraDir.z = glm::cos(p) * glm::cos(y);

    // cameraDir = glm::normalize(cameraDir);
    cameraRight = glm::normalize(glm::cross(cameraDir, ABSOLUTE_UP));

    cameraUp = glm::cross(cameraRight, cameraDir);

}

void Camera::moveDir(float dPitch, float dYaw)
{
    pitch += mouseSens * dPitch;
    if (pitch > 89.0f)
        pitch = 89.0f;
    else if (pitch < -89.0f)
        pitch = -89.0f;

    yaw += mouseSens * dYaw;
    if (yaw > 180.0f)
        yaw -= 360.0f;
    else if (yaw < -180.0f)
        yaw += 360.0f;

    recalculateOrientation();
}
