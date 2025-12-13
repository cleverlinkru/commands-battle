#pragma once
#include <vector>
#include "World.h"
#include "Cell.h"

class World;
class Cell;

class Map
{
    public:
        Map(World* world, int w, int h);
        void draw();
        World* getWorld();

    private:
        int _w, _h;
        World* world;
        std::vector<Cell*> _cells;

        Cell* getCell(int x, int y);
};
