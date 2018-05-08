#include "Square.hpp"

#include <iostream>
#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

Square::Square(float x, float y, float size)
    : x(x)
    , y(y)
    , size(size)
    , type(new NormalSquare)
{ }

Square::~Square()
{
    delete type;
}

bool Square::contains(float x, float y)
{
    return
        x >= this->x - size/2 && x <= this->x + size/2 &&
        y <= this->y + size/2 && y >= this->y - size/2;
}

void Square::draw()
{
    std::vector<float> color = type->color();
    glColor3f(color[0], color[1], color[2]);
    glRectf(x-size/2, y+size/2,
            x+size/2, y-size/2);
}

class SquareType;
void Square::setType(SquareType* type)
{
    this->type = type;
}

void Square::click()
{
    if (dynamic_cast<WallSquare*>(type))
        setType(new NormalSquare);
    else
        setType(new WallSquare);
}

SquareType* Square::getType()
{
    return type;
}
