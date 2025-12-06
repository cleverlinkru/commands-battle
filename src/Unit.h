#pragma once
#include <cmath>
#include "World.h"
#include "Camera.h"
#include "InputEvent.h"
#include "ViewingZone.h"

class World;

class Unit
{
    public:
        Unit(
            World* world,
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
        World* world;
        long x, y, directionX, directionY;
        int r, commandIndex;
        bool isAlive = true;
        bool isSelected = false;
        ViewingZone* viewingZone;
        Camera* camera;
        void handlerClickInside();
        void handlerClickOutside();
        void generateVisibleMasks();
};
