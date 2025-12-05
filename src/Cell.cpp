#include "Cell.h"

Cell::Cell(long x, long y)
{
    this->x = x;
    this->y = y;
}

void Cell::setCamera(Camera* camera)
{
    this->camera = camera;
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
