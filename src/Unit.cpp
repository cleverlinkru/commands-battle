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
    this->visibleMask = new VisibleMask(this);
    this->math = new Math();
}

std::tuple<long, long, int, long, long> Unit::getBaseParams()
{
    return std::make_tuple(x, y, r, directionX, directionY);
}

int Unit::getCommandIndex()
{
    return commandIndex;
}

World* Unit::getWorld()
{
    return world;
}

ViewingZone* Unit::getViewingZone()
{
    return this->viewingZone;
}

VisibleMask* Unit::getVisibleMask()
{
    return this->visibleMask;
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

void Unit::input(InputEvent* event)
{
    if (event->type() == InputEvent::MousePressedLeft) {
        double s = math->vectorLength(event->x() + camera->x() - x, event->y() + camera->y() - y);
        bool inside = s < r;
        if (inside) {
            handlerClickInside();
        } else {
debug = true;
setDirection(camera->x() + event->x(), camera->y() + event->y());
            handlerClickOutside();
        }
    }
if ((event->type() == InputEvent::MouseMoved) && debug) {
setDirection(camera->x() + event->x(), camera->y() + event->y());
}
if (event->type() == InputEvent::MouseReleasedLeft) {
debug = false;
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

    visibleMask->generate();

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
