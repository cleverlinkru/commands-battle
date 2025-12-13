#include "Cell.h"

Cell::Cell(Map* map, long x, long y)
{
    this->map = map;
    this->x = x;
    this->y = y;
}

void Cell::draw()
{
    Camera* camera = map->getWorld()->getEngine()->getCamera();
    if (
        camera->x() > (x + 1) * w ||
        camera->y() > (y + 1) * h ||
        camera->x() + camera->w() < x * w ||
        camera->y() + camera->h() < y * h
    ) {
        return;
    }

    camera->drawCell(x * w, y * h);
}
