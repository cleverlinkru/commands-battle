#pragma once
#include "World.h"
#include "Camera.h"
#include "Wall.h"
#include "Unit.h"

class WorldGenerator
{
    public:
        World* create(Camera* camera);
};
