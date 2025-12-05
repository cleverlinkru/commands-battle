#include "WorldGenerator.h"

World* WorldGenerator::create()
{
    Map* map = new Map(50, 30);
    std::vector<Wall> wallList;
    std::vector<Unit> unitList;
    return new World(map, wallList, unitList);
}
