#include "Panel.h"

Panel::Panel(sf::RenderWindow* window)
{
    this->window = window;
    this->btnPause = createButton(0);
    this->btnStep = createButton(1);
    this->btnPlay = createButton(2);
    this->btnDest = createButton(3);
    this->btnMove = createButton(4);
    this->btnFire = createButton(5);
}

InputEvent* Panel::input(InputEvent* event)
{
    InputEvent* _event;

    _event = btnPause->input(event);
    if (_event->type() != 0) return _event;

    _event = btnStep->input(event);
    if (_event->type() != 0) return _event;

    _event = btnPlay->input(event);
    if (_event->type() != 0) return _event;

    _event = btnDest->input(event);
    if (_event->type() != 0) return _event;

    _event = btnMove->input(event);
    if (_event->type() != 0) return _event;

    _event = btnFire->input(event);
    if (_event->type() != 0) return _event;

    return event;
}

void Panel::draw()
{
    drawBack();
    btnPause->draw();
    btnStep->draw();
    btnPlay->draw();
    btnDest->draw();
    btnMove->draw();
    btnFire->draw();
}

void Panel::drawBack()
{
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(180, 30));
    rectangle.setFillColor(sf::Color(60,60,60,255));
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setOutlineThickness(3);
    rectangle.setPosition(3, 3);
    window->draw(rectangle);
}

Button* Panel::createButton(int index)
{
    return new Button(
       window,
       3 + index * 30,
       3,
       30,
       30,
       sf::Color(60,60,60,255),
       sf::Color(50,50,50,255),
       sf::Color(40,40,40,255),
       sf::Color::Black,
       index
    );
}
