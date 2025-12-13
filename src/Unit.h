#pragma once
#include <cmath>
#include <tuple>
#include "World.h"
#include "Camera.h"
#include "InputEvent.h"
#include "ViewingZone.h"
#include "VisibleMask.h"
#include "Math.h"

class World;
class VisibleMask;

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
        std::tuple<long, long, int, long, long> getBaseParams();
        int getCommandIndex();
        World* getWorld();
        ViewingZone* getViewingZone();
        VisibleMask* getVisibleMask();
        void setPosition(long x, long y);
        void setDirection(long x, long y);
        void input(InputEvent* event);
        void draw();

    private:
        World* world;
        long x, y, directionX, directionY;
        int r, commandIndex;
        bool isAlive = true;
        bool isSelected = false;
        ViewingZone* viewingZone;
        VisibleMask* visibleMask;
        Camera* camera;
        Math* math;
bool debug = false;

        void handlerClickInside();
        void handlerClickOutside();
        void generateVisibleMasks();
};
