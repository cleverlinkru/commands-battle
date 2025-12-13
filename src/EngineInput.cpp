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
                mouseEvent.raise(EventMousePressedLeft, event.mouseButton.x, event.mouseButton.y);
            }
            if (event.mouseButton.button == sf::Mouse::Right) {
                mouseEvent.raise(EventMousePressedRight, event.mouseButton.x, event.mouseButton.y);
            }
        }

        if (event.type == sf::Event::MouseButtonReleased) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                mouseEvent.raise(EventMouseReleasedLeft, event.mouseButton.x, event.mouseButton.y);
            }
            if (event.mouseButton.button == sf::Mouse::Right) {
                mouseEvent.raise(EventMouseReleasedRight, event.mouseButton.x, event.mouseButton.y);
            }
        }

        if (event.type == sf::Event::MouseMoved) {
            mouseEvent.raise(EventMouseMoved, event.mouseMove.x, event.mouseMove.y);
        }
    }
}
