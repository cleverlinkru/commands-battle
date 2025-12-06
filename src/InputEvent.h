#pragma once

class InputEvent
{
    public:
        static const int MousePressedLeft = 1;
        static const int MousePressedRight = 2;
        static const int MouseReleasedLeft = 3;
        static const int MouseReleasedRight = 4;
        static const int MouseMoved = 5;
        static const int ButtonPanel = 6;
        static const int ButtonPause = 7;
        static const int ButtonStep = 8;
        static const int ButtonPlay = 9;
        static const int ButtonDir = 10;
        static const int ButtonMove = 11;
        static const int ButtonFire = 12;

        InputEvent(int type, int x, int y);
        int type();
        int x();
        int y();

    private:
        int _type, _x, _y;
};
