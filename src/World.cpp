#include "World.h"

void World::setCamera(Camera* camera)
{
    this->camera = camera;

    if (this->map != nullptr) {
        this->map->setCamera(camera);
    }

    for (Wall* wall : walls) {
        wall->setCamera(camera);
    }
}

void World::setMap(Map* map)
{
    this->map = map;
}

void World::addWall(Wall* wall)
{
    this->walls.push_back(wall);
}

void World::addUnit(Unit* unit)
{
    this->units.push_back(unit);
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


}
