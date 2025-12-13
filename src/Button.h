#pragma once
#include <SFML/Graphics.hpp>
#include "InputEvent.h"

class Button
{
    public:
        Button(
            sf::RenderWindow* window,
            int x,
            int y,
            int w,
            int h,
            sf::Color bgDef,
            sf::Color bgHov,
            sf::Color bgCl,
            sf::Color brd,
            int icon
        );
        InputEvent* input(InputEvent* event);
        void draw();

    private:
        sf::RenderWindow* window;
        int x, y, w, h, icon;
        sf::Color bgDef;
        sf::Color bgHov;
        sf::Color bgCl;
        sf::Color brd;
        sf::Color bg;

        void drawBtn();
        void drawPause();
        void drawStep();
        void drawPlay();
        void drawDir();
        void drawMove();
        void drawFire();
};
