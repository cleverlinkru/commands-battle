#include "Control.h"

Control::Control(Camera* camera)
{
    this->camera = camera;
}

void Control::leftPress(int x, int y)
{
}

void Control::leftRelease(int x, int y)
{
}

void Control::rightPress(int x, int y)
{
    this->x = x;
    this->y = y;
    isMoveCam = true;
}

void Control::rightRelease(int x, int y)
{
    isMoveCam = false;
}

void Control::move(int x, int y)
{
    if (isMoveCam) {
        int moveX = this->x - x;
        int moveY = this->y - y;
        this->x = x;
        this->y = y;
        this->camera->move(moveX, moveY);
    }
}
