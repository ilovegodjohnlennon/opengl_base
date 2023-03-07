#pragma once

struct InputMap
{
    float mouseDx = 0.0f;
    float mouseDy = 0.0f;

    bool mouseMoved = false;
    bool forwards = false;
    bool backwards = false;
    bool left = false;
    bool right = false;
};

struct MousePos
{
    double x;
    double y;
    double px;
    double py;

    bool moved = false;
};