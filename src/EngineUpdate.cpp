#include "Engine.h"

void Engine::update()
{
    world->update();
    camera->update();
}
