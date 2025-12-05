#include "Camera.h"

Camera::Camera(long startX, long startY, int w, int h, World* world, sf::RenderWindow* window)
{
    this->x = startX;
    this->y = startY;
    this->w = w;
    this->h = h;
    this->world = world;
    this->window = window;
}

void Camera::update()
{
}

void Camera::draw()
{
    Map* map = this->world->getMap();

    long cellFromX = this->x / map->cellW();
    long cellFromY = this->y / map->cellH();
    long cellToX = (this->x + this->w) / map->cellW();
    long cellToY = (this->y + this->h) / map->cellH();

    for (long y = cellFromY; y <= cellToY; y++) {
        for (long x = cellFromX; x <= cellToX; x++) {
            if (x < 0 || y < 0 || x >= map->w() || y >= map->h()) {
                continue;
            }

            int posX = x * map->cellW() - this->x;
            int posY = y * map->cellH() - this->y;

            sf::RectangleShape rectangle;
            rectangle.setSize(sf::Vector2f(map->cellW(), map->cellH()));
            rectangle.setFillColor(sf::Color(50,50,50,255));
            rectangle.setOutlineColor(sf::Color(60,60,60,255));
            rectangle.setOutlineThickness(3);
            rectangle.setPosition(posX, posY);

            window->draw(rectangle);
        }
    }
}

void Camera::move(int x, int y)
{
    this->x += x;
    this->y += y;
}
