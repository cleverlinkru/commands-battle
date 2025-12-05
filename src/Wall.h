#pragma once
#include "Camera.h"

class Wall
{
    public:
        Wall(long x, long y, long w, long h);
        void setCamera(Camera* camera);
        void draw();

    private:
        long x, y, w, h;
        Camera* camera;
};
