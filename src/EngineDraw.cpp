#include "Engine.h"

void Engine::draw()
{
    window->clear(sf::Color::Black);

    world->draw();
    panel->draw();

    window->display();
}
