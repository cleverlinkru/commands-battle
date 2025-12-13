#pragma once
#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "Button.h"
#include "Event.h"

class Engine;

class Panel
{
    public:
        static const int EventButtonPause = 1;
        static const int EventButtonStep = 2;
        static const int EventButtonPlay = 3;
        static const int EventButtonDir = 4;
        static const int EventButtonMove = 5;
        static const int EventButtonFire = 6;

        Panel(sf::RenderWindow* window, Engine* engine);
        void draw();

    private:
        sf::RenderWindow* window;
        Engine* engine;
        Event<int> buttonClickEvent;
        Button* btnPause;
        Button* btnStep;
        Button* btnPlay;
        Button* btnDir;
        Button* btnMove;
        Button* btnFire;

        void drawBack();
        Button* createButton(int index);
        bool buttonClickEventHandler(int type, int x, int y);
};
