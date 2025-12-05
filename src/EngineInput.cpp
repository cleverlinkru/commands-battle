#include "Engine.h"

void Engine::input()
{
    sf::Event event;
    while (window->pollEvent(event)) {

        if (event.type == sf::Event::Closed) {
            window->close();
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                world->input(new InputEvent(InputEvent::MousePressedLeft, event.mouseButton.x, event.mouseButton.y));
            }
            if (event.mouseButton.button == sf::Mouse::Right) {
                world->input(new InputEvent(InputEvent::MousePressedRight, event.mouseButton.x, event.mouseButton.y));
            }
        }

        if (event.type == sf::Event::MouseButtonReleased) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                world->input(new InputEvent(InputEvent::MouseReleasedLeft, event.mouseButton.x, event.mouseButton.y));
            }
            if (event.mouseButton.button == sf::Mouse::Right) {
                world->input(new InputEvent(InputEvent::MouseReleasedRight, event.mouseButton.x, event.mouseButton.y));
            }
        }

        if (event.type == sf::Event::MouseMoved) {
            world->input(new InputEvent(InputEvent::MouseMoved, event.mouseMove.x, event.mouseMove.y));
        }
    }
}
