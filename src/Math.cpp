#include "Math.h"

double Math::vectorLength(double x, double y)
{
    return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
}

double Math::vectorAngle(double x, double y)
{
    double s = vectorLength(x, y);
    double angle = std::acos(x / s);
    if (y < 0) {
        angle = -angle;
    }
    return angleDiapasoning(angle);
}

std::tuple<double, double> Math::vectorPoint(double a, double l)
{
    double x = l * std::cos(a);
    double y = l * std::sin(a);
    return std::make_tuple(x, y);
}

double Math::angleDiapasoning(double a)
{
    if (a < 0) {
        while (a < 0) {
            a += 2 * M_PI;
        }
    } else if (a > 2 * M_PI) {
        while (a > 2 * M_PI) {
            a -= 2 * M_PI;
        }
    }
    return a;
}
