#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include "World.h"
#include "WorldGenerator.h"
#include "Camera.h"
#include "InputEvent.h"

class Engine
{
    public:
        Engine();

        void run();

    private:
        sf::RenderWindow* window;
        World* world;

        void delay();
        void input();
        void update();
        void draw();
};
