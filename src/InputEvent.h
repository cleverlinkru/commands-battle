#pragma once

class InputEvent
{
    public:
        static const int MousePressedLeft = 1;
        static const int MousePressedRight = 2;
        static const int MouseReleasedLeft = 3;
        static const int MouseReleasedRight = 4;
        static const int MouseMoved = 5;

        InputEvent(int type, int x, int y);
        int type();
        int x();
        int y();

    private:
        int _type, _x, _y;
};
