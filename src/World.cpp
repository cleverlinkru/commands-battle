#include "World.h"

World::World(Engine* engine, int mapW, int mapH, Commands* commands)
{
    this->engine = engine;
    this->map = new Map(this, mapW, mapH);
    this->commands = commands;
}

void World::addWall(long x, long y, long w, long h)
{
    this->walls.push_back(new Wall(this, x, y, w, h));
}

std::vector<Wall*> World::getWalls()
{
    return walls;
}

void World::addUnit(long x, long y, int r, long directionX, long directionY, int commandIndex, int viewingAngle)
{
    this->units.push_back(new Unit(this, x, y, r, directionX, directionY, commandIndex, viewingAngle));
}

std::vector<Unit*> World::getUnits()
{
    return units;
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

Commands* World::getCommands()
{
    return this->commands;
}

Engine* World::getEngine()
{
    return this->engine;
}
