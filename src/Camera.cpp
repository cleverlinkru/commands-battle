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

void Camera::drawUnit(long x, long y, int r, long dirX, long dirY, int com, bool isSelected)
{
    int posX = x - _x;
    int posY = y - _y;

    sf::RenderTexture renderTexture;
    renderTexture.create(r * 2, r * 2);
    renderTexture.clear(sf::Color::Transparent);

    sf::CircleShape circle(r);
    if (com == 1) {
        circle.setFillColor(sf::Color::Red);
    } else if (com = 2) {
        circle.setFillColor(sf::Color::Blue);
    }
    circle.setPosition(0, 0);
    renderTexture.draw(circle);

    if (isSelected) {
        sf::CircleShape circle2;
        circle2.setRadius(r - 3);
        circle2.setFillColor(sf::Color::Transparent);
        circle2.setOutlineColor(sf::Color::Yellow);
        circle2.setOutlineThickness(3);
        circle2.setPosition(3, 3);
        renderTexture.draw(circle2);
    }

    int s = std::sqrt(std::pow(dirX - x, 2) + std::pow(dirY - y, 2));
    int lx = (dirX - x) * r / s;
    int ly = (dirY - y) * r / s;
    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(r, r), sf::Color::Black),
        sf::Vertex(sf::Vector2f(r + lx, r + ly), sf::Color::Black),
    };
    sf::VertexArray lineArray(sf::Lines, 2);
    lineArray[0] = line[0];
    lineArray[1] = line[1];
    renderTexture.draw(lineArray);

    renderTexture.display();
    sf::Sprite sprite(renderTexture.getTexture());
    sprite.setPosition(posX - r, posY - r);
    window->draw(sprite);
}

void Camera::drawViewingZone(long x, long y, int angle, long directionX, long directionY, long len)
{
    long vCenterX = directionX - x;
    long vCenterY = directionY - y;
    long sCenter = sqrt(pow(vCenterX, 2) + pow(vCenterY, 2));
    long sDestSide = sCenter * std::tan(6.28 * angle / 360);
    vCenterX = vCenterX * len / sCenter;
    vCenterY = vCenterY * len / sCenter;
    long vRightX = vCenterY;
    long vRightY = -vCenterX;
    long vLeftX = -vCenterY;
    long vLeftY = vCenterX;
    vRightX = vRightX * sDestSide / sCenter;
    vRightY = vRightY * sDestSide / sCenter;
    vLeftX = vLeftX * sDestSide / sCenter;
    vLeftY = vLeftY * sDestSide / sCenter;
    vRightX += vCenterX + x;
    vRightY += vCenterY + y;
    vLeftX += vCenterX + x;
    vLeftY += vCenterY + y;

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(x - _x, y - _y));
    triangle.setPoint(1, sf::Vector2f(vRightX - _x, vRightY - _y));
    triangle.setPoint(2, sf::Vector2f(vLeftX - _x, vLeftY - _y));
    triangle.setFillColor(sf::Color(0, 255, 0, 100));
    window->draw(triangle);
}

void Camera::move(int x, int y)
{
    this->_x += x;
    this->_y += y;
}
