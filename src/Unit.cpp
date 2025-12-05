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

void Unit::draw()
{
    
}
