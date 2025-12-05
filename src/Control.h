#pragma once
#include "Camera.h"

class Control
{
    public:
        Control(Camera* camera);
        void leftPress(int x, int y);
        void leftRelease(int x, int y);
        void rightPress(int x, int y);
        void rightRelease(int x, int y);
        void move(int x, int y);

    private:
        Camera* camera;
        bool isMoveCam = false;
        int x, y;
};
