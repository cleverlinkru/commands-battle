#include "Unit.h"

Unit::Unit(Camera* camera, long x, long y, int r, long dirX, long dirY, int com)
{
    this->camera = camera;
    this->x = x;
    this->y = y;
    this->r = r;
    this->dirX = dirX;
    this->dirY = dirY;
    this->com = com;
}

void Unit::input(InputEvent* event)
{
    if (event->type() == InputEvent::MousePressedLeft) {
        dirX = event->x() + camera->x();
        dirY = event->y() + camera->y();
    }
}

void Unit::draw()
{
    if (
        camera->x() > x + r ||
        camera->y() > y + r ||
        camera->x() + camera->w() < x - r ||
        camera->y() + camera->h() < y - r
    ) {
        return;
    }

    camera->drawUnit(x, y, r, dirX, dirY, com);
}
