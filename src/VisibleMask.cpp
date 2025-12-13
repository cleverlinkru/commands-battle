#include "VisibleMask.h"

VisibleMask::VisibleMask(Unit* unit)
{
    this->unit = unit;
}

bool VisibleMask::getValue(int x, int y)
{
    auto [ux, uy, ur, directionX, directionY] = unit->getBaseParams();
    return mask[y * ur * 2 + x];
}

void VisibleMask::generate()
{
    mask.clear();
    World* world = unit->getWorld();
    auto [ux, uy, ur, directionX, directionY] = unit->getBaseParams();
    int commandIndex = unit->getCommandIndex();

    if (world->getCommands()->current() == commandIndex) {
        createMonoMask(ur, true);
        return;
    }

    for (int y = -ur; y < ur; y++) {
        for (int x = -ur; x < ur; x++) {
            double sToCenter = math->vectorLength(x, y);
            if (sToCenter > ur) {
                mask.push_back(false);
                continue;
            }

            bool visible = false;

            for (Unit* watchUnit : world->getUnits()) {
                if ( watchUnit == unit || watchUnit->getCommandIndex() != world->getCommands()->current() ) {
                    continue;
                }

                if (checkWatchUnit(watchUnit, ux + x, uy + y)) {
                    visible = true;
                    break;
                }
            }

            mask.push_back(visible);
        }
    }

}

void VisibleMask::createMonoMask(int r, bool val)
{
    for (int y = 0; y < r * 2; y++) {
        for (int x = 0; x < r * 2; x++) {
            mask.push_back(val);
        }
    }
}

bool VisibleMask::checkWatchUnit(Unit* watchUnit, long pointX, long pointY)
{
    World* world = unit->getWorld();
    auto [ux, uy, ur, directionX, directionY] = watchUnit->getBaseParams();
    ViewingZone* viewingZone = watchUnit->getViewingZone();
    auto [centerAngle, leftAngle, rightAngle] = viewingZone->getAngles();
    double toPointAngle = math->vectorAngle(pointX - ux, pointY - uy);
    double toPointS = math->vectorLength(pointX - ux, pointY - uy);
    if (!math->angleBetween(toPointAngle, leftAngle, rightAngle)) {
        return false;
    }

    for (Wall* wall : world->getWalls()) {
        auto [wallX, wallY, wallW, wallH] = wall->getBaseParams();
        if (
            math->checkHorLineOverlaps(toPointAngle, toPointS, wallX - ux, wallY - uy, wallW) ||
            math->checkHorLineOverlaps(toPointAngle, toPointS, wallX - ux, wallY - uy + wallH, wallW) ||
            math->checkVerLineOverlaps(toPointAngle, toPointS, wallX - ux, wallY - uy, wallH) ||
            math->checkVerLineOverlaps(toPointAngle, toPointS, wallX - ux + wallW, wallY - uy, wallH)
        ) {
            return false;
        }
    }

    return true;
}
