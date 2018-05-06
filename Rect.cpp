#include "Rect.hpp"

Rect::Rect(float x, float y, float width, float height)
    : x(x)
    , y(y)
    , height(height)
    , width(width)
{ }

bool Rect::contains(float x, float y)
{
    return
        x >= this->x && x <= this->x + width &&
        y <= this->y && y >= this->y - height;
}
