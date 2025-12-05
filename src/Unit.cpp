#include "Unit.h"

Unit::Unit(long x, long y, int r, long dirX, long dirY, int com)
{
    this->x = x;
    this->y = y;
    this->r = r;
    this->dirX = dirX;
    this->dirY = dirY;
    this->com = com;
}

void Unit::setCamera(Camera* camera)
{
    this->camera = camera;
}

void Unit::draw()
{
    
}
