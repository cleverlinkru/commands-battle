#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Cell.h"
#include "InputEvent.h"
#include <iostream> //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1

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
        void drawWall(long x, long y, long w, long h);
        void drawUnit(long x, long y, int r, long dirX, long dirY, int com, bool isSelected);
        void drawViewingZone(long x, long y, int angle, long directionX, long directionY, long len);

    private:
        long _x, _y, _w, _h;
        sf::RenderWindow* window;
        bool isMoving = false;
        int movingX, movingY;

        void move(int x, int y);
};
