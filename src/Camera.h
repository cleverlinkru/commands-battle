#pragma once
#include <SFML/Graphics.hpp>
#include "World.h"

class Camera
{
    public:
        Camera(long startX, long startY, int w, int h, World* world, sf::RenderWindow* window);
        void update();
        void draw();
        void move(int x, int y);

    private:
        long x, y, w, h;
        World* world;
        sf::RenderWindow* window;
};
