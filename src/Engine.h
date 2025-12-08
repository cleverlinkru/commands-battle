#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include "World.h"
#include "WorldGenerator.h"
#include "Camera.h"
#include "InputEvent.h"
#include "Panel.h"
#include "Cursor.h"
#include "VisibleMaskCreator.h"

class Engine
{
    public:
        Engine();
        void run();

    private:
        sf::RenderWindow* window;
        Panel* panel;
        Cursor* cursor;
        World* world;
        VisibleMaskCreator* visibleMaskCreator;

        void delay();
        void input();
        void update();
        void draw();
        void handleEvent(InputEvent* event);
};
