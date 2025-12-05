#pragma once
#include "Camera.h"

class Unit
{
    public:
        Unit(long x, long y, int r, long dirX, long dirY, int com);
        void setCamera(Camera* camera);
        void draw();

    private:
        long x, y, dirX, dirY;
        int r, com;
        bool isAlive = true;
        Camera* camera;
};
