#include "Wall.h"

Wall::Wall(long x, long y, long w, long h)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

void Wall::setCamera(Camera* camera)
{
    this->camera = camera;
}

void Wall::draw()
{
    if (
        camera->x() > x + w ||
        camera->y() > y + h ||
        camera->x() + camera->w() < x ||
        camera->y() + camera->h() < y
    ) {
        return;
    }

    camera->drawWall(x, y, w, h);
}
