#include "Engine.h"

void Engine::input()
{
    sf::Event event;
    InputEvent* _event;
    while (window->pollEvent(event)) {

        if (event.type == sf::Event::Closed) {
            window->close();
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                _event = panel->input(new InputEvent(InputEvent::MousePressedLeft, event.mouseButton.x, event.mouseButton.y));
                world->input(_event);
            }
            if (event.mouseButton.button == sf::Mouse::Right) {
                _event = panel->input(new InputEvent(InputEvent::MousePressedRight, event.mouseButton.x, event.mouseButton.y));
                world->input(_event);
            }
        }

        if (event.type == sf::Event::MouseButtonReleased) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                _event = panel->input(new InputEvent(InputEvent::MouseReleasedLeft, event.mouseButton.x, event.mouseButton.y));
                world->input(_event);
            }
            if (event.mouseButton.button == sf::Mouse::Right) {
                _event = panel->input(new InputEvent(InputEvent::MouseReleasedRight, event.mouseButton.x, event.mouseButton.y));
                world->input(_event);
            }
        }

        if (event.type == sf::Event::MouseMoved) {
            _event = panel->input(new InputEvent(InputEvent::MouseMoved, event.mouseMove.x, event.mouseMove.y));
            world->input(_event);
        }
    }
}
