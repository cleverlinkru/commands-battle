#pragma once
#include <vector>
#include "Camera.h"
#include "Cell.h"

class Map
{
    public:
        Map(int w, int h);
        void setCamera(Camera* camera);
        void draw();

    private:
        int _w, _h;
        Camera* camera;
        std::vector<Cell*> _cells;

        Cell* getCell(int x, int y);
};
