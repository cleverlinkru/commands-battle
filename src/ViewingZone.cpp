#include "ViewingZone.h"

ViewingZone::ViewingZone(Camera* camera, long x, long y, int angle, long directionX, long directionY)
{
    this->camera = camera;
    this->x = x;
    this->y = y;
    this->angle = angle;
    this->directionX = directionX;
    this->directionY = directionY;

    this->math = new Math();

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

std::tuple<double, double, double> ViewingZone::getAngles()
{
    return std::make_tuple(centerAngle, leftAngle, rightAngle);
}

void ViewingZone::setPosition(long x, long y)
{
    this->x = x;
    this->y = y;
    calc();
}

void ViewingZone::setDirection(long x, long y)
{
    this->directionX = x;
    this->directionY = y;
    calc();
}

void ViewingZone::calc()
{
    double centerX = directionX - x;
    double centerY = directionY - y;
    centerAngle = math->vectorAngle(centerX, centerY);
    double sideAngle = 2 * M_PI * (double)angle / 720;
    double sideLen = abs((double)len / std::cos(sideAngle));
    leftAngle = math->angleDiapasoning(centerAngle - sideAngle);
    rightAngle = math->angleDiapasoning(centerAngle + sideAngle);
    auto [_leftX, _leftY] = math->vectorPoint(leftAngle, sideLen);
    auto [_rightX, _rightY] = math->vectorPoint(rightAngle, sideLen);
    leftX = x + _leftX;
    leftY = y + _leftY;
    rightX = x + _rightX;
    rightY = y + _rightY;
}
