#include "Engine.h"

void Engine::update()
{
    bool needUpdate = ticker->update();

    if (!needUpdate) {
        return;
    }

    world->update();
}
