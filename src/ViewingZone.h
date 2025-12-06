#pragma once
#include "Camera.h"

class ViewingZone
{
    public:
        ViewingZone(Camera* camera, long x, long y, int angle, long directionX, long directionY);
        void show();
        void hide();
        void draw();

    private:
        static const long len = 500;
        bool isShow = false;
        long x, y, directionX, directionY;
        int angle;
        Camera* camera;
};
