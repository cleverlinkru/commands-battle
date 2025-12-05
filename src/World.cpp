#include "World.h"

World::World(Map* map, std::vector<Wall> wallList, std::vector<Unit> unitList)
{
    this->map = map;
    this->wallList = wallList;
    this->unitList = unitList;
}

void World::update()
{

}

Map* World::getMap()
{
    return this->map;
}
