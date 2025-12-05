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
    int cellFromX = camera->x() / Cell::w;
    int cellFromY = camera->y() / Cell::h;
    int cellToX = (camera->x() + camera->w()) / Cell::w;
    int cellToY = (camera->y() + camera->h()) / Cell::h;

    for (int y = cellFromY; y <= cellToY; y++) {
        for (int x = cellFromX; x <= cellToX; x++) {
            if (x < 0 || y < 0 || x >= _w || y >= _h) {
                continue;
            }

            Cell* cell = getCell(x, y);

            cell->draw();
        }
    }
}

Cell* Map::getCell(int x, int y)
{
    return _cells[y * _w + x];
}
