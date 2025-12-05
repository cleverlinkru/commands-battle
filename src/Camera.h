#pragma once
#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "InputEvent.h"

class Camera
{
    public:
        Camera(long startX, long startY, int w, int h, sf::RenderWindow* window);
        void input(InputEvent* event);
        int x();
        int y();
        int w();
        int h();
        void drawCell(long x, long y);

    private:
        long _x, _y, _w, _h;
        sf::RenderWindow* window;
        bool isMoving = false;
        int movingX, movingY;

        void move(int x, int y);
};
