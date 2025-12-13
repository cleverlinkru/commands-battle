#pragma once
#include <tuple>
#include "World.h"
#include "Camera.h"

class World;

class Wall
{
    public:
        Wall(World* world, long x, long y, long w, long h);
        std::tuple<long, long, long, long> getBaseParams();
        void draw();

    private:
        long x, y, w, h;
        World* world;
};
