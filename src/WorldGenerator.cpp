#include "WorldGenerator.h"

World* WorldGenerator::create()
{
    World* world = new World();

    world->setMap(new Map(50, 30));

    world->addWall(new Wall(60,60,100,30));

    world->addUnit(new Unit());

    return world;
}
