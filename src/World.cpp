#include "World.h"

World::World(Camera* camera, int mapW, int mapH)
{
    this->camera = camera;
    this->map = new Map(camera, mapW, mapH);
}

void World::addWall(long x, long y, long w, long h)
{
    this->walls.push_back(new Wall(camera, x, y, w, h));
}

void World::addUnit(long x, long y, int r, long directionX, long directionY, int commandIndex, int viewingAngle)
{
    this->units.push_back(new Unit(camera, x, y, r, directionX, directionY, commandIndex, viewingAngle));
}

void World::input(InputEvent* event)
{
    camera->input(event);

    for (Unit* unit : units) {
        unit->input(event);
    }
}

void World::World::update()
{

}

void World::draw()
{
    map->draw();

    for (Wall* wall : walls) {
        wall->draw();
    }

    for (Unit* unit : units) {
        unit->draw();
    }

    for (Unit* unit : units) {
        unit->getViewingZone()->draw();
    }
}
