#pragma once
#include "World.h"
#include "Engine.h"
#include "Wall.h"
#include "Unit.h"
#include "Commands.h"

class World;
class Engine;

class WorldGenerator
{
    public:
        World* create(Engine* engine);
};
