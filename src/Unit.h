#pragma once
#include <cmath>
#include <tuple>
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
        std::tuple<long, long, int, long, long> getBaseParams();
        int getCommandIndex();
        ViewingZone* getViewingZone();
        void setPosition(long x, long y);
        void setDirection(long x, long y);
        void setVisibleMask(std::vector<bool> visibleMask);
        std::vector<bool> getVisibleMask();
        void input(InputEvent* event);
        void draw();

    private:
        World* world;
        long x, y, directionX, directionY;
        int r, commandIndex;
        bool isAlive = true;
        bool isSelected = false;
        ViewingZone* viewingZone;
        std::vector<bool> visibleMask;
        Camera* camera;
        void handlerClickInside();
        void handlerClickOutside();
        void generateVisibleMasks();
};
