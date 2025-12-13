#pragma once
#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "Event.h"

class Engine;

class Button
{
    public:
        Event<> clickEvent;

        Button(
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
        );
        void draw();

    private:
        sf::RenderWindow* window;
        Engine* engine;
        int x, y, w, h, icon;
        sf::Color bgDef;
        sf::Color bgHov;
        sf::Color bgCl;
        sf::Color brd;
        sf::Color bg;

        void mouseEventHandler(int type, int x, int y);
        void drawBtn();
        void drawPause();
        void drawStep();
        void drawPlay();
        void drawDir();
        void drawMove();
        void drawFire();
};
