#include "VisibleMaskCreator.h"

VisibleMaskCreator::VisibleMaskCreator(World* world)
{
    this->world = world;

    this->math = new Math();
}

void VisibleMaskCreator::createGlobal()
{
    std::vector<Unit*> units = world->getUnits();
    std::vector<Wall*> walls = world->getWalls();

    for (Unit* unit : units) {
        auto [ux, uy, ur, directionX, directionY] = unit->getBaseParams();
        int commandIndex = unit->getCommandIndex();

        if (world->getCommands()->current() == commandIndex) {
            unit->setVisibleMask(createMonoMask(ur, true));
            continue;
        }

        std::vector<bool> mask;

        for (int y = -ur; y < ur; y++) {
            for (int x = -ur; x < ur; x++) {
                double sToCenter = math->vectorLength(x, y);
                if (sToCenter > ur) {
                    mask.push_back(false);
                    continue;
                }

                bool visible = false;

                for (Unit* watchUnit : units) {
                    if ( watchUnit == unit || watchUnit->getCommandIndex() != world->getCommands()->current() ) {
                        continue;
                    }

                    auto [wx, wy, wr, wDirectionX, wDirectionY] = watchUnit->getBaseParams();
                    ViewingZone* viewingZone = watchUnit->getViewingZone();
                    auto [centerAngle, leftAngle, rightAngle] = viewingZone->getAngles();
                    double pointAngle = math->vectorAngle(ux - wx + x, uy - wy + y);

                    if (
                        leftAngle <= rightAngle && leftAngle <= pointAngle && pointAngle <= rightAngle ||
                        leftAngle > rightAngle && (leftAngle <= pointAngle || pointAngle <= rightAngle)
                    ) {
                        visible = true;
                        break;
                    }
                }

                mask.push_back(visible);
            }
        }

        unit->setVisibleMask(mask);
    }
}

std::vector<bool> VisibleMaskCreator::createMonoMask(int r, bool val)
{
    std::vector<bool> mask;
    for (int y = 0; y < r * 2; y++) {
        for (int x = 0; x < r * 2; x++) {
            mask.push_back(val);
        }
    }
    return mask;
}
