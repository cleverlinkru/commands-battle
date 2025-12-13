#include "Cursor.h"

Cursor::Cursor(sf::RenderWindow* window, Engine* engine)
{
    this->window = window;
    this->engine = engine;

    engine->mouseEvent.subscribe([this](int type, int x, int y) {
        this->mouseEventHandler(type, x, y);
        return true;
    });
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

bool Cursor::mouseEventHandler(int type, int x, int y)
{
    if (type == Engine::EventMouseMoved) {
        this->x = x;
        this->y = y;
    }
    return true;
}
