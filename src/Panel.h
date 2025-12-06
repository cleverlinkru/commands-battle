#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"

class Panel
{
    public:
        Panel(sf::RenderWindow* window);
        InputEvent* input(InputEvent* event);
        void draw();

    private:
        sf::RenderWindow* window;
        Button* btnPause;
        Button* btnStep;
        Button* btnPlay;
        Button* btnDest;
        Button* btnMove;
        Button* btnFire;
        void drawBack();
        Button* createButton(int index);
};
