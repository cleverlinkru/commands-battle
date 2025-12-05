#pragma once
#include <vector>
#include "Map.h"
#include "Wall.h"
#include "Unit.h"

class World
{
    public:
        World(Map* map, std::vector<Wall> wallList, std::vector<Unit> unitList);
        void update();
        Map* getMap();

    private:
        Map* map;
        std::vector<Wall> wallList;
        std::vector<Unit> unitList;
};
