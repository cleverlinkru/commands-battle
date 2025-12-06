#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>
#include "Camera.h"

class ViewingZone
{
    public:
        ViewingZone(Camera* camera, long x, long y, int angle, long directionX, long directionY);
        void show();
        void hide();
        void draw();
        std::vector<bool> generateVisibleMask(long rx, long ry, long rw, long rh);

    private:
        static const long len = 500;
        bool isShow = false;
        long x, y, directionX, directionY, leftX, leftY, rightX, rightY;
        int angle;
        Camera* camera;
        void calc();
        double vectorLength(double x, double y);
        double vectorAngle(double x, double y);
        std::tuple<double, double> vectorPoint(double a, double l);
};
