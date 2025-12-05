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
        void setCamera(Camera* camera);
        void setMap(Map* map);
        void addWall(Wall* wall);
        void addUnit(Unit* unit);
        void input(InputEvent* event);
        void update();
        void draw();

    private:
        Camera* camera;
        Map* map;
        std::vector<Wall*> walls;
        std::vector<Unit*> units;
};
