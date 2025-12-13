#pragma once
#include <cmath>
#include <vector>
#include <tuple>
#include "Unit.h"
#include "Math.h"

class Unit;

class ViewingZone
{
    public:
        ViewingZone(Unit* unit, long x, long y, int angle, long directionX, long directionY);
        void show();
        void hide();
        void draw();
        std::tuple<double, double, double> getAngles();
        void setPosition(long x, long y);
        void setDirection(long x, long y);

    private:
        static const long len = 500;
        bool isShow = false;
        long x, y, directionX, directionY, leftX, leftY, rightX, rightY;
        int angle;
        double centerAngle, leftAngle, rightAngle;
        Unit* unit;
        Math* math;

        void calc();
};
