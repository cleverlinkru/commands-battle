#include "Engine.h"

void Engine::draw()
{
    window->clear(sf::Color::Black);

    visibleMaskCreator->createGlobal();
    world->draw();
    panel->draw();
    cursor->draw();

    window->display();
}
