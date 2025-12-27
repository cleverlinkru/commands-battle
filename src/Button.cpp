#include "Button.h"

Button::Button(
    sf::RenderWindow* window,
    Engine* engine,
    int x,
    int y,
    int w,
    int h,
    sf::Color bgDef,
    sf::Color bgHov,
    sf::Color bgCl,
    sf::Color brd,
    int icon
)
{
    this->window = window;
    this->engine = engine;
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->bgDef = bgDef;
    this->bgHov = bgHov;
    this->bgCl = bgCl;
    this->brd = brd;
    this->icon = icon;
    this->bg = bgDef;

    engine->mouseEvent.subscribe([this](int evType, int evX, int evY) {
        return this->mouseEventHandler(evType, evX, evY);
    });
}

void Button::draw()
{
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(w, h));
    rectangle.setFillColor(bg);
    rectangle.setOutlineColor(brd);
    rectangle.setOutlineThickness(3);
    rectangle.setPosition(x, y);
    window->draw(rectangle);

    if (icon == 0) {
        drawPause();
    } else if (icon == 1) {
        drawStep();
    } else if (icon == 2) {
        drawPlay();
    } else if (icon == 3) {
        drawDir();
    } else if (icon == 4) {
        drawMove();
    } else if (icon == 5) {
        drawFire();
    } else if (icon == 6) {
        drawViewingZone();
    }
}

void Button::setChecked(bool val)
{
    checked = val;

    if (checked) {
        bg = bgCl;
    } else {
        bg = bgDef;
    }
}

bool Button::mouseEventHandler(int evType, int evX, int evY)
{
    bool inside =
        x <= evX &&
        evX <= x + w &&
        y <= evY &&
        evY <= y + h;

    if (evType == Engine::EventMouseMoved) {
        if (inside) {
            bg = bgHov;
        } else if (checked) {
            bg = bgCl;
        } else {
            bg = bgDef;
        }
    }

    if (evType == Engine::EventMousePressedLeft) {
        if (inside) {
            bg = bgCl;
            clickEvent.raise();
            return false;
        }
    }

    if (evType == Engine::EventMouseReleasedLeft) {
        if (inside) {
            bg = bgHov;
        } else if (checked) {
            bg = bgCl;
        } else {
            bg = bgDef;
        }
    }

    return true;
}

void Button::drawPause()
{
    sf::RectangleShape rectangle;
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setSize(sf::Vector2f(3, h - 10));
    rectangle.setPosition(x + 6, y + 5);
    window->draw(rectangle);
    rectangle.setPosition(x + w - 12, y + 5);
    window->draw(rectangle);
}

void Button::drawStep()
{
    sf::RectangleShape rectangle;
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setSize(sf::Vector2f(3, h - 10));
    rectangle.setPosition(x + 5, y + 5);
    window->draw(rectangle);
    rectangle.setPosition(x + w - 16, y + 5);
    window->draw(rectangle);
    rectangle.setSize(sf::Vector2f(3, h / 2));
    rectangle.setPosition(x + w - 16, y + 5);
    rectangle.setRotation(-30);
    window->draw(rectangle);
    rectangle.setPosition(x + w - 8, y + h / 2 - 3);
    rectangle.setRotation(30);
    window->draw(rectangle);
}

void Button::drawPlay()
{
    sf::RectangleShape rectangle;
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setSize(sf::Vector2f(3, h - 10));
    rectangle.setPosition(x + w / 2 - 4, y + 5);
    window->draw(rectangle);
    rectangle.setSize(sf::Vector2f(3, h / 2));
    rectangle.setPosition(x + w / 2 - 4, y + 5);
    rectangle.setRotation(-30);
    window->draw(rectangle);
    rectangle.setPosition(x + w / 2 + 4, y + h / 2 - 3);
    rectangle.setRotation(30);
    window->draw(rectangle);
}

void Button::drawDir()
{
    sf::RectangleShape rectangle;
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setSize(sf::Vector2f(3, h - 5));
    rectangle.setPosition(x + 5, y + 6);
    rectangle.setRotation(-40);
    window->draw(rectangle);
    rectangle.setPosition(x + w - 10, y + 4);
    rectangle.setRotation(40);
    window->draw(rectangle);
}

void Button::drawMove()
{
    sf::RectangleShape rectangle;
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setSize(sf::Vector2f(3, h - 4));
    rectangle.setPosition(x + w / 2 - 2, y + 2);
    window->draw(rectangle);
    rectangle.setSize(sf::Vector2f(w - 7, 3));
    rectangle.setPosition(x + 3, y + h / 2 - 1);
    window->draw(rectangle);
}

void Button::drawFire()
{
    sf::CircleShape circle;
    circle.setRadius(w / 2 - 4);
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineThickness(3);
    circle.setOutlineColor(sf::Color::Black);
    circle.setPosition(x + 4, y + 4);
    window->draw(circle);

    sf::RectangleShape rectangle;
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setSize(sf::Vector2f(3, h - 4));
    rectangle.setPosition(x + w / 2 - 2, y + 2);
    window->draw(rectangle);
    rectangle.setSize(sf::Vector2f(w - 7, 3));
    rectangle.setPosition(x + 3, y + h / 2 - 1);
    window->draw(rectangle);
}

void Button::drawViewingZone()
{
    sf::RectangleShape rectangle;
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setSize(sf::Vector2f(3, h - 4));
    rectangle.setPosition(x + 4, y + 2);
    rectangle.setRotation(-20);
    window->draw(rectangle);
    rectangle.setSize(sf::Vector2f(3, h - 4));
    rectangle.setPosition(x + w - 7, y + 2);
    rectangle.setRotation(20);
    window->draw(rectangle);
}
