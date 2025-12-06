#include "Cursor.h"

Cursor::Cursor(sf::RenderWindow* window)
{
    this->window = window;
}

void Cursor::input(InputEvent* event)
{
    if (event->type() == InputEvent::MouseMoved) {
        x = event->x();
        y = event->y();
    }
}

void Cursor::draw()
{
    sf::Vertex lineVertices1[] = {
        sf::Vertex(sf::Vector2f(x, y - 15), sf::Color::White),
        sf::Vertex(sf::Vector2f(x, y + 15), sf::Color::White),
    };
    sf::Vertex lineVertices2[] = {
        sf::Vertex(sf::Vector2f(x - 15, y), sf::Color::White),
        sf::Vertex(sf::Vector2f(x + 15, y), sf::Color::White),
    };
    window->draw(lineVertices1, 2, sf::Lines);
    window->draw(lineVertices2, 2, sf::Lines);
}
