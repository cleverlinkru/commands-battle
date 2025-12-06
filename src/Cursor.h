#pragma once
#include <SFML/Graphics.hpp>
#include "InputEvent.h"

class Cursor
{
    public:
        Cursor(sf::RenderWindow* window);
        void input(InputEvent* event);
        void draw();

    private:
        sf::RenderWindow* window;
        int x, y;
};
