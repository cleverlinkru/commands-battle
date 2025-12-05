#include "InputEvent.h"

InputEvent::InputEvent(int type, int x, int y)
{
    this->_type = type;
    this->_x = x;
    this->_y = y;
}

int InputEvent::type()
{
    return this->_type;
}

int InputEvent::x()
{
    return this->_x;
}

int InputEvent::y()
{
    return this->_y;
}
