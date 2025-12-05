#include "Engine.h"

void Engine::draw()
{
    window.clear(sf::Color::Black);

    camera->draw();

    window.display();
}
