#pragma once
#include "Camera.h"

class Camera;

class Cell
{
    public:
        Cell(long x, long y);
        void setCamera(Camera* camera);
        void draw(long mapW, long mapH);

        static const int w = 50;
        static const int h = 50;

    private:
        long x, y;
        Camera* camera;
};
