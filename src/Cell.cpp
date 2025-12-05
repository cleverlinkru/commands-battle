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

void Cell::draw()
{
    camera->drawCell(x * w, y * h);
}
