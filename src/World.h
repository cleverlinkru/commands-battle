#pragma once
#include <vector>
#include "InputEvent.h"
#include "Camera.h"
#include "Map.h"
#include "Wall.h"
#include "Unit.h"

class World
{
    public:
        World(Camera* camera, int mapW, int mapH);
        void addWall(long x, long y, long w, long h);
        void addUnit(long x, long y, int r, long dirX, long dirY, int com);
        void input(InputEvent* event);
        void update();
        void draw();

    private:
        Camera* camera;
        Map* map;
        std::vector<Wall*> walls;
        std::vector<Unit*> units;
};
