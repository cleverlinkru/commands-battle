#include "Panel.h"

Panel::Panel(sf::RenderWindow* window, Engine* engine)
{
    this->window = window;
    this->engine = engine;

    this->btnPause = createButton(0);
    this->btnStep = createButton(1);
    this->btnPlay = createButton(2);
    this->btnDir = createButton(3);
    this->btnMove = createButton(4);
    this->btnFire = createButton(5);
    this->btnViewingZone = createButton(6);

    this->btnPause->clickEvent.subscribe([this]() {
        this->buttonClickEvent.raise(Panel::EventButtonPause);
        return false;
    });
    this->btnStep->clickEvent.subscribe([this]() {
        this->buttonClickEvent.raise(Panel::EventButtonStep);
        return false;
    });
    this->btnPlay->clickEvent.subscribe([this]() {
        this->buttonClickEvent.raise(Panel::EventButtonPlay);
        return false;
    });
    this->btnDir->clickEvent.subscribe([this]() {
        this->buttonClickEvent.raise(Panel::EventButtonDir);
        return false;
    });
    this->btnMove->clickEvent.subscribe([this]() {
        this->buttonClickEvent.raise(Panel::EventButtonMove);
        return false;
    });
    this->btnFire->clickEvent.subscribe([this]() {
        this->buttonClickEvent.raise(Panel::EventButtonFire);
        return false;
    });
    this->btnViewingZone->clickEvent.subscribe([this]() {
        this->buttonClickEvent.raise(Panel::EventButtonViewingZone);
        return false;
    });
}

void Panel::setChecked(int buttonIndex, bool val)
{
    if (buttonIndex == 1) {
        btnPause->setChecked(val);
    } else if (buttonIndex == 2) {
        btnStep->setChecked(val);
    } else if (buttonIndex == 3) {
        btnPlay->setChecked(val);
    } else if (buttonIndex == 4) {
        btnDir->setChecked(val);
    } else if (buttonIndex == 5) {
        btnMove->setChecked(val);
    } else if (buttonIndex == 6) {
        btnFire->setChecked(val);
    } else if (buttonIndex == 7) {
        btnViewingZone->setChecked(val);
    }
}

void Panel::draw()
{
    drawBack();
    btnPause->draw();
    btnStep->draw();
    btnPlay->draw();
    btnDir->draw();
    btnMove->draw();
    btnFire->draw();
    btnViewingZone->draw();
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
       engine,
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
