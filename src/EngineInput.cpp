#include "Engine.h"

void Engine::input()
{
    sf::Event event;
    while (window.pollEvent(event)) {

        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                control->leftPress(event.mouseButton.x, event.mouseButton.y);
            }
            if (event.mouseButton.button == sf::Mouse::Right) {
                control->rightPress(event.mouseButton.x, event.mouseButton.y);
            }
        }

        if (event.type == sf::Event::MouseButtonReleased) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                control->leftRelease(event.mouseButton.x, event.mouseButton.y);
            }
            if (event.mouseButton.button == sf::Mouse::Right) {
                control->rightRelease(event.mouseButton.x, event.mouseButton.y);
            }
        }

        if (event.type == sf::Event::MouseMoved) {
            control->move(event.mouseMove.x, event.mouseMove.y);
        }
    }
}
