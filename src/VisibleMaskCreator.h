#pragma once
#include "World.h"
#include "Unit.h"
#include "ViewingZone.h"
#include "Math.h"

class VisibleMaskCreator
{
    public:
        VisibleMaskCreator(World* world);
        void createGlobal();

    private:
        World* world;
        Math* math;
        std::vector<bool> createMonoMask(int r, bool val);
};
