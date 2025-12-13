#include "Map.h"

Map::Map(World* world, int w, int h)
{
    this->world = world;

    this->_w = w;
    this->_h = h;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            Cell* cell = new Cell(this, x, y);
            _cells.push_back(cell);
        }
    }
}

void Map::draw()
{
    for (int y = 0; y < _h; y++) {
        for (int x = 0; x < _w; x++) {
            Cell* cell = getCell(x, y);
            cell->draw();
        }
    }
}

World* Map::getWorld()
{
    return this->world;
}

Cell* Map::getCell(int x, int y)
{
    return _cells[y * _w + x];
}
