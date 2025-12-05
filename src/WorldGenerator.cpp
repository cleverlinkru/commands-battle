#include "WorldGenerator.h"

World* WorldGenerator::create()
{
    World* world = new World();

    world->setMap(new Map(50, 30));

    world->addWall(new Wall(500,300,100,30));

    world->addUnit(new Unit(550, 400, 25, 10, 10, 1));
    world->addUnit(new Unit(300, 200, 25, 300, 300, 2));

    return world;
}
