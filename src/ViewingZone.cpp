#include "ViewingZone.h"

ViewingZone::ViewingZone(Camera* camera, long x, long y, int angle, long directionX, long directionY)
{
    this->camera = camera;
    this->x = x;
    this->y = y;
    this->angle = angle;
    this->directionX = directionX;
    this->directionY = directionY;

    calc();
}

void ViewingZone::show()
{
    isShow = true;
}

void ViewingZone::hide()
{
    isShow = false;
}

void ViewingZone::draw()
{
    if (!isShow) {
        return;
    }

    camera->drawViewingZone(x, y, leftX, leftY, rightX, rightY);
}

std::vector<bool> ViewingZone::generateVisibleMask(long rx, long ry, long rw, long rh)
{
    std::vector<bool> vMask;

    return vMask;
}

void ViewingZone::calc()
{
    double centerX = directionX - x;
    double centerY = directionY - y;
    double centerAngle = vectorAngle(centerX, centerY);
    double leftAngle = centerAngle - 2 * M_PI * (double)angle / 720;
    double rightAngle = centerAngle + 2 * M_PI * (double)angle / 720;
    double leftLen = abs((double)len / std::cos(leftAngle));
    double rightLen = abs((double)len / std::cos(rightAngle));
    auto [_leftX, _leftY] = vectorPoint(leftAngle, leftLen);
    auto [_rightX, _rightY] = vectorPoint(rightAngle, rightLen);
    leftX = x + _leftX;
    leftY = y + _leftY;
    rightX = x + _rightX;
    rightY = y + _rightY;
}

double ViewingZone::vectorLength(double x, double y)
{
    return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
}

double ViewingZone::vectorAngle(double x, double y)
{
    double s = vectorLength(x, y);
    double angle = std::acos(x / s);
    if (y < 0) {
        angle = 2 * M_PI - angle;
    }
    return angle;
}

std::tuple<double, double> ViewingZone::vectorPoint(double a, double l)
{
    double x = l * std::cos(a);
    double y = l * std::sin(a);
    return std::make_tuple(x, y);
}
