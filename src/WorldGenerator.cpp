#include "WorldGenerator.h"

World* WorldGenerator::create(Camera* camera)
{
    World* world = new World(camera, 50, 30);

    world->addWall(500,300,100,30);

    world->addUnit(550, 400, 25, 10, 10, 1);
    world->addUnit(300, 200, 25, 300, 300, 2);

    return world;
}
