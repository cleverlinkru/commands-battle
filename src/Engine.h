#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Engine
{
    public:
        Engine();

        void run();

    private:
        RenderWindow window;

        void input();
        void update();
        void draw();
};
