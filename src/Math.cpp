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

bool Math::angleBetween(double angle, double leftAngle, double rightAngle)
{
    return leftAngle <= rightAngle && leftAngle <= angle && angle <= rightAngle ||
        leftAngle > rightAngle && (leftAngle <= angle || angle <= rightAngle);
}

bool Math::checkHorLineOverlaps(double a, double s, long lineX, long lineY, long lineW)
{
    auto [pointX, pointY] = vectorPoint(a, s);

    if (
        lineY >= 0 && pointY < lineY ||
        lineY < 0 && pointY > lineY
    ) {
        return false;
    }

    double toLineLeftS;
    double toLineLeftAngle;
    double toLineRightS;
    double toLineRightAngle;
    if (lineY >= 0) {
        toLineLeftS = vectorLength(lineX + lineW, lineY);
        toLineLeftAngle = vectorAngle(lineX + lineW, lineY);
        toLineRightS = vectorLength(lineX, lineY);
        toLineRightAngle = vectorAngle(lineX, lineY);
    } else {
        toLineLeftS = vectorLength(lineX, lineY);
        toLineLeftAngle = vectorAngle(lineX, lineY);
        toLineRightS = vectorLength(lineX + lineW, lineY);
        toLineRightAngle = vectorAngle(lineX + lineW, lineY);
    }

    return angleBetween(a, toLineLeftAngle, toLineRightAngle);
}

bool Math::checkVerLineOverlaps(double a, double s, long lineX, long lineY, long lineH)
{
    auto [pointX, pointY] = vectorPoint(a, s);

    if (
        lineX >= 0 && pointX < lineX ||
        lineX < 0 && pointX > lineX
    ) {
        return false;
    }

    double toLineLeftS;
    double toLineLeftAngle;
    double toLineRightS;
    double toLineRightAngle;
    if (lineX >= 0) {
        toLineLeftS = vectorLength(lineX, lineY);
        toLineLeftAngle = vectorAngle(lineX, lineY);
        toLineRightS = vectorLength(lineX, lineY + lineH);
        toLineRightAngle = vectorAngle(lineX, lineY + lineH);
    } else {
        toLineLeftS = vectorLength(lineX, lineY + lineH);
        toLineLeftAngle = vectorAngle(lineX, lineY + lineH);
        toLineRightS = vectorLength(lineX, lineY);
        toLineRightAngle = vectorAngle(lineX, lineY);
    }

    return angleBetween(a, toLineLeftAngle, toLineRightAngle);
}
