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
                handleEvent(new InputEvent(InputEvent::MousePressedLeft, event.mouseButton.x, event.mouseButton.y));
            }
            if (event.mouseButton.button == sf::Mouse::Right) {
                handleEvent(new InputEvent(InputEvent::MousePressedRight, event.mouseButton.x, event.mouseButton.y));
            }
        }

        if (event.type == sf::Event::MouseButtonReleased) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                handleEvent(new InputEvent(InputEvent::MouseReleasedLeft, event.mouseButton.x, event.mouseButton.y));
            }
            if (event.mouseButton.button == sf::Mouse::Right) {
                handleEvent(new InputEvent(InputEvent::MouseReleasedRight, event.mouseButton.x, event.mouseButton.y));
            }
        }

        if (event.type == sf::Event::MouseMoved) {
            handleEvent(new InputEvent(InputEvent::MouseMoved, event.mouseMove.x, event.mouseMove.y));
        }
    }
}

void Engine::handleEvent(InputEvent* event)
{
    cursor->input(event);
    event = panel->input(event);
    world->input(event);
}
