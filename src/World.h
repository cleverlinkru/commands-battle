#pragma once
#include <vector>
#include "InputEvent.h"
#include "Camera.h"
#include "Map.h"
#include "Wall.h"
#include "Unit.h"
#include "Commands.h"

class Unit;

class World
{
    public:
        World(Camera* camera, int mapW, int mapH, Commands* commands);
        void addWall(long x, long y, long w, long h);
        void addUnit(long x, long y, int r, long directionX, long directionY, int commandIndex, int viewingAngle);
        void input(InputEvent* event);
        void update();
        void draw();
        Commands* getCommands();

    private:
        Camera* camera;
        Map* map;
        std::vector<Wall*> walls;
        std::vector<Unit*> units;
        Commands* commands;
};
