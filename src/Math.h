#pragma once
#include <cmath>
#include <tuple>

class Math
{
    public:
        double vectorLength(double x, double y);
        double vectorAngle(double x, double y);
        std::tuple<double, double> vectorPoint(double a, double l);
        double angleDiapasoning(double a);
        bool angleBetween(double angle, double leftAngle, double rightAngle);
        bool checkHorLineOverlaps(double a, double s, long lineX, long lineY, long lineW);
        bool checkVerLineOverlaps(double a, double s, long lineX, long lineY, long lineH);
};
