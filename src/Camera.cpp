#include "Camera.h"

Camera::Camera(long startX, long startY, int w, int h, sf::RenderWindow* window)
{
    this->_x = startX;
    this->_y = startY;
    this->_w = w;
    this->_h = h;
    this->window = window;
}

void Camera::input(InputEvent* event)
{
    if (event->type() == InputEvent::MousePressedRight) {
        isMoving = true;
        movingX = event->x();
        movingY = event->y();
    }

    if (event->type() == InputEvent::MouseReleasedRight) {
        isMoving = false;
        movingX = event->x();
        movingY = event->y();
    }

    if (event->type() == InputEvent::MouseMoved) {
        if (isMoving) {
            move(movingX - event->x(), movingY - event->y());
        }
        movingX = event->x();
        movingY = event->y();
    }
}

int Camera::x()
{
    return this->_x;
}

int Camera::y()
{
    return this->_y;
}

int Camera::w()
{
    return this->_w;
}

int Camera::h()
{
    return this->_h;
}

void Camera::drawCell(long x, long y)
{
    int posX = x - _x;
    int posY = y - _y;

    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(Cell::w, Cell::h));
    rectangle.setFillColor(sf::Color(50,50,50,255));
    rectangle.setOutlineColor(sf::Color(60,60,60,255));
    rectangle.setOutlineThickness(3);
    rectangle.setPosition(posX, posY);
    window->draw(rectangle);
}

void Camera::drawWall(long x, long y, long w, long h)
{
    int posX = x - _x;
    int posY = y - _y;

    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(w, h));
    rectangle.setFillColor(sf::Color(46,27,27,255));
    rectangle.setOutlineColor(sf::Color(0,0,0,255));
    rectangle.setOutlineThickness(3);
    rectangle.setPosition(posX, posY);
    window->draw(rectangle);
}

void Camera::move(int x, int y)
{
    this->_x += x;
    this->_y += y;
}
