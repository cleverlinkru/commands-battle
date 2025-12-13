#include "Wall.h"

Wall::Wall(Camera* camera, long x, long y, long w, long h)
{
    this->camera = camera;
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

std::tuple<long, long, long, long> Wall::getBaseParams()
{
    return std::make_tuple(x, y, w, h);
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
