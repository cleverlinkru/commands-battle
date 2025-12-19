#pragma once
#include <vector>
#include "Engine.h"
#include "Map.h"
#include "Wall.h"
#include "Unit.h"
#include "Commands.h"

class Engine;
class Wall;
class Unit;

class World
{
    public:
        World(Engine* engine, int mapW, int mapH, Commands* commands);
        void addWall(long x, long y, long w, long h);
        std::vector<Wall*> getWalls();
        void addUnit(long x, long y, int r, long directionX, long directionY, int commandIndex, int viewingAngle);
        std::vector<Unit*> getUnits();
        void update();
        void draw();
        Commands* getCommands();
        Engine* getEngine();

    private:
        Engine* engine;
        Map* map;
        std::vector<Wall*> walls;
        std::vector<Unit*> units;
        Commands* commands;
};
