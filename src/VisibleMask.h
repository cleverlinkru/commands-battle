#pragma once
#include <vector>
#include "Unit.h"
#include "Wall.h"
#include "Math.h"

class Unit;

class VisibleMask
{
    public:
        VisibleMask(Unit* unit);
        bool getValue(int x, int y);
        void generate();

    private:
        std::vector<bool> mask;
        Unit* unit;
        Math* math;

        void createMonoMask(int r, bool val);
        bool checkWatchUnit(Unit* watchUnit, long pointX, long pointY);
};
