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
};
