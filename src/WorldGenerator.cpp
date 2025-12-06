#include "WorldGenerator.h"

World* WorldGenerator::create(Camera* camera)
{
    Commands* commands = new Commands(2);
//    commands->set(1);

    World* world = new World(camera, 50, 30, commands);

    world->addWall(500,300,100,30);

    world->addUnit(500, 500, 25, 1000, 500, 1, 60);
    world->addUnit(1000, 500, 25, 800, 500, 1, 60);

    return world;
}
