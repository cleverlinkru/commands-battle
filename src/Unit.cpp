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

std::tuple<long, long, int, long, long> Unit::getBaseParams()
{
    return std::make_tuple(x, y, r, directionX, directionY);
}

int Unit::getCommandIndex()
{
    return commandIndex;
}

ViewingZone* Unit::getViewingZone()
{
    return this->viewingZone;
}

void Unit::setPosition(long x, long y)
{
    this->x = x;
    this->y = y;
    this->viewingZone->setPosition(x, y);
}

void Unit::setDirection(long x, long y)
{
    this->directionX = x;
    this->directionY = y;
    this->viewingZone->setDirection(x, y);
}

void Unit::setVisibleMask(std::vector<bool> visibleMask)
{
    this->visibleMask = visibleMask;
}

std::vector<bool> Unit::getVisibleMask()
{
    return this->visibleMask;
}

void Unit::input(InputEvent* event)
{
    if (event->type() == InputEvent::MousePressedLeft) {
        int s = sqrt(pow(event->x() + camera->x() - x, 2) + pow(event->y() + camera->y() - y, 2));
        bool inside = s < r;
        if (inside) {
            handlerClickInside();
        } else {
setDirection(camera->x() + event->x(), camera->y() + event->y());
            handlerClickOutside();
        }
    }
if (event->type() == InputEvent::MousePressedRight && isSelected) {
setPosition(camera->x() + event->x(), camera->y() + event->y());
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

    camera->drawUnit(x, y, r, directionX, directionY, commandIndex, isSelected, visibleMask);
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
