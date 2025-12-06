#pragma once
#include <cmath>
#include "Camera.h"
#include "InputEvent.h"
#include "ViewingZone.h"

class Unit
{
    public:
        Unit(
            Camera* camera,
            long x,
            long y,
            int r,
            long directionX,
            long directionY,
            int commandIndex,
            int viewingAngle
        );
        ViewingZone* getViewingZone();
        void input(InputEvent* event);
        void draw();

    private:
        long x, y, directionX, directionY;
        int r, commandIndex;
        bool isAlive = true;
        bool isSelected = false;
        ViewingZone* viewingZone;
        Camera* camera;
};
