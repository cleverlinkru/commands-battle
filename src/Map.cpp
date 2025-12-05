#include "Map.h"

Map::Map(int w, int h)
{
    this->_w = w;
    this->_h = h;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            Cell* cell = new Cell(x, y);
            _cells.push_back(cell);
        }
    }
}

void Map::setCamera(Camera* camera)
{
    this->camera = camera;

    for (int y = 0; y < _h; y++) {
        for (int x = 0; x < _w; x++) {
            Cell* cell = getCell(x, y);
            cell->setCamera(camera);
        }
    }
}

void Map::draw()
{
    for (int y = 0; y < _h; y++) {
        for (int x = 0; x < _w; x++) {
            Cell* cell = getCell(x, y);
            cell->draw(_w, _h);
        }
    }
}

Cell* Map::getCell(int x, int y)
{
    return _cells[y * _w + x];
}
