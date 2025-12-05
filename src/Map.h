#pragma once
#include <vector>
#include "Cell.h"

class Map
{
    public:
        Map(int w, int h);
        int w();
        int h();
        int cellW();
        int cellH();

    private:
        int _w, _h;
        const int _cellW = 50;
        const int _cellH = 50;
        std::vector<Cell*> cellList;
};
