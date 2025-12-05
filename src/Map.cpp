#include "Map.h"

Map::Map(int w, int h)
{
    this->_w = w;
    this->_h = h;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            Cell* cell = new Cell(x, y);
            cellList.push_back(cell);
        }
    }
}

int Map::w()
{
    return this->_w;
}

int Map::h()
{
    return this->_h;
}

int Map::cellW()
{
    return this->_cellW;
}

int Map::cellH()
{
    return this->_cellH;
}
