#pragma once
#include "Map.h"
#include "Camera.h"

class Map;
class Camera;

class Cell
{
    public:
        static const int w = 50;
        static const int h = 50;

        Cell(Map* map, long x, long y);
        void draw();

    private:
        long x, y;
        Map* map;
};
