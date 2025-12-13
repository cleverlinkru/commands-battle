#pragma once
#include <SFML/Graphics.hpp>
#include "Engine.h"

class Engine;

class Cursor
{
    public:
        Cursor(sf::RenderWindow* window, Engine* engine);
        void draw();

    private:
        sf::RenderWindow* window;
        Engine* engine;
        int x, y;

        bool mouseEventHandler(int type, int x, int y);
};
