#include "World.h"

World::World(Camera* camera, int mapW, int mapH)
{
    this->camera = camera;
    this->map = new Map(camera, mapW, mapH);
}

void World::addWall(long x, long y, long w, long h)
{
    this->walls.push_back(new Wall(camera, x, y, w, h));
}

void World::addUnit(long x, long y, int r, long dirX, long dirY, int com)
{
    this->units.push_back(new Unit(camera, x, y, r, dirX, dirY, com));
}

void World::input(InputEvent* event)
{
    camera->input(event);
}

void World::World::update()
{

}

void World::draw()
{
    map->draw();

    for (Wall* wall : walls) {
        wall->draw();
    }

    for (Unit* unit : units) {
        unit->draw();
    }
}
