#include "Cell.h"

Cell::Cell(Camera* camera, long x, long y)
{
    this->camera = camera;
    this->x = x;
    this->y = y;
}

void Cell::draw(long mapW, long mapH)
{
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
