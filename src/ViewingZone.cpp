#include "ViewingZone.h"

ViewingZone::ViewingZone(Camera* camera, long x, long y, int angle, long directionX, long directionY)
{
    this->camera = camera;
    this->x = x;
    this->y = y;
    this->angle = angle;
    this->directionX = directionX;
    this->directionY = directionY;
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

    camera->drawViewingZone(x, y, angle, directionX, directionY, len);
}
