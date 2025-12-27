#pragma once
#include <cmath>
#include <tuple>
#include "World.h"
#include "Panel.h"
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
        bool getIsSelected();
        void draw();
        void update();

    private:
        World* world;
        long x, y, directionX, directionY;
        int r, commandIndex;
        bool isAlive = true;
        bool isSelected = false;
        bool isViewingZoneVisible = false;
        ViewingZone* viewingZone;
        VisibleMask* visibleMask;
        Math* math;

        bool mouseEventHandler(int eventType, int eventX, int eventY);
        bool panelButtonClickEventHandler(int buttonIndex);
        void handlerClickInside();
        void handlerClickOutside();
        void generateVisibleMasks();
};
