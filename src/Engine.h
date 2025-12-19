#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include "World.h"
#include "WorldGenerator.h"
#include "Camera.h"
#include "Panel.h"
#include "Cursor.h"
#include "Event.h"
#include "Ticker.h"

class Engine
{
    public:
        static const int EventMousePressedLeft = 1;
        static const int EventMousePressedRight = 2;
        static const int EventMouseReleasedLeft = 3;
        static const int EventMouseReleasedRight = 4;
        static const int EventMouseMoved = 5;

        Event<int, int, int> mouseEvent;

        Engine();
        void run();
        Camera* getCamera();
        Panel* getPanel();

    private:
        sf::RenderWindow* window;
        Panel* panel;
        Cursor* cursor;
        World* world;
        Camera* camera;
        Ticker* ticker;

        void delay();
        void input();
        void update();
        void draw();
};
