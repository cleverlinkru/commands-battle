#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Cell.h"
#include "Math.h"
#include "InputEvent.h"
#include "VisibleMask.h"

class VisibleMask;

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
        void drawUnit(long x, long y, int r, long dirX, long dirY, int com, bool isSelected, VisibleMask* visibleMask);
        void drawViewingZone(long x1, long y1, long x2, long y2, long x3, long y3);

    private:
        long _x, _y, _w, _h;
        sf::RenderWindow* window;
        bool isMoving = false;
        int movingX, movingY;
        Math* math;

        void move(int x, int y);
};
