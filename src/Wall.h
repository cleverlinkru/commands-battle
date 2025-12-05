#pragma once
#include "Camera.h"

class Wall
{
    public:
        Wall(Camera* camera, long x, long y, long w, long h);
        void draw();

    private:
        long x, y, w, h;
        Camera* camera;
};
