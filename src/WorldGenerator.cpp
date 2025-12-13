#include "WorldGenerator.h"

World* WorldGenerator::create(Engine* engine)
{
    Commands* commands = new Commands(2);
    commands->set(1);

    World* world = new World(engine, 50, 30, commands);

    world->addWall(600, 600, 30, 30);

    world->addUnit(300, 300, 25, 800, 800, 1, 60);
    world->addUnit(700, 500, 25, 1000, 1000, 2, 60);

    return world;
}
