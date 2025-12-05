#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include "World.h"
#include "WorldGenerator.h"
#include "Camera.h"
#include "Control.h"

class Engine
{
    public:
        Engine();

        void run();

    private:
        sf::RenderWindow window;
        World* world;
        Camera* camera;
        Control* control;

        void delay();
        void input();
        void update();
        void draw();
};
