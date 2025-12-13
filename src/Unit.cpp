#include "Unit.h"

Unit::Unit(
    World* world,
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
    this->x = x;
    this->y = y;
    this->r =r;
    this->directionX = directionX;
    this->directionY = directionY;
    this->commandIndex = commandIndex;

    this->viewingZone = new ViewingZone(this, x, y, viewingAngle, directionX, directionY);
    this->visibleMask = new VisibleMask(this);
    this->math = new Math();

    world->getEngine()->mouseEvent.subscribe([this](int type, int x, int y) {
        this->mouseEventHandler(type, x, y);
        return true;
    });
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

void Unit::draw()
{
    Camera* camera = world->getEngine()->getCamera();

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

bool Unit::mouseEventHandler(int eventType, int eventX, int eventY)
{
    Camera* camera = world->getEngine()->getCamera();

    if (eventType == Engine::EventMousePressedLeft) {
        double s = math->vectorLength(eventX + camera->x() - x, eventY + camera->y() - y);
        bool inside = s < r;
        if (inside) {
            handlerClickInside();
        } else {
            handlerClickOutside();
        }
    }

    return true;
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
