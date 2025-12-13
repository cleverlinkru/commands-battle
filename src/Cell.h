#pragma once
#include "Camera.h"

class Camera;

class Cell
{
    public:
        static const int w = 50;
        static const int h = 50;

        Cell(Camera* camera, long x, long y);
        void draw();

    private:
        long x, y;
        Camera* camera;
};
