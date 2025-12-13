#include "Wall.h"

Wall::Wall(World* world, long x, long y, long w, long h)
{
    this->world = world;
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
    Camera* camera = world->getEngine()->getCamera();
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
