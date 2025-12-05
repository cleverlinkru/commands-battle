#pragma once
#include "Camera.h"
#include "InputEvent.h"

class Unit
{
    public:
        Unit(Camera* camera, long x, long y, int r, long dirX, long dirY, int com);
        void input(InputEvent* event);
        void draw();

    private:
        long x, y, dirX, dirY;
        int r, com;
        bool isAlive = true;
        Camera* camera;
};
