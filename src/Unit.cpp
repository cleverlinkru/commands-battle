#include "Unit.h"

Unit::Unit(
    World* world,
    Camera* camera,
    long x,
    long y,
    int r,
    long directionX,
    long directionY,
    int commandIndex,
    int viewingAngle
)
{
    this->world = world;
    this->camera = camera;
    this->x = x;
    this->y = y;
    this->r =r;
    this->directionX = directionX;
    this->directionY = directionY;
    this->commandIndex = commandIndex;
    this->viewingZone = new ViewingZone(camera, x, y, viewingAngle, directionX, directionY);
}

ViewingZone* Unit::getViewingZone()
{
    return this->viewingZone;
}

void Unit::input(InputEvent* event)
{
    if (event->type() == InputEvent::MousePressedLeft) {
        int s = sqrt(pow(event->x() + camera->x() - x, 2) + pow(event->y() + camera->y() - y, 2));
        bool inside = s < r;
        if (inside) {
            handlerClickInside();
        } else {
            handlerClickOutside();
        }
    }
}

void Unit::draw()
{
    if (
        camera->x() > x + r ||
        camera->y() > y + r ||
        camera->x() + camera->w() < x - r ||
        camera->y() + camera->h() < y - r ||
        (
            world->getCommands()->current() > 0 &&
            world->getCommands()->current() != commandIndex
        )
    ) {
        return;
    }

    generateVisibleMasks();

    camera->drawUnit(x, y, r, directionX, directionY, commandIndex, isSelected);
}

void Unit::handlerClickInside()
{
    if (world->getCommands()->current() > 0 && world->getCommands()->current() != commandIndex) {
        return;
    }

    isSelected = true;
    viewingZone->show();
    world->getCommands()->set(commandIndex);
}

void Unit::handlerClickOutside()
{
    isSelected = false;
    viewingZone->hide();
}

void Unit::generateVisibleMasks()
{
//    std::vector<bool> vMask = viewingZone->generateVisibleMask(1000 - 25, 500 - 25, 1000 + 25, 500 + 25);
}
