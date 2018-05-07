#include "Square.hpp"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

Square::Square(float x, float y, float size,
               float r, float g, float b)
    : x(x)
    , y(y)
    , size(size)
    , r(r)
    , g(g)
    , b(b)
{ }

bool Square::contains(float x, float y)
{
    return
        x >= this->x - size/2 && x <= this->x + size/2 &&
        y <= this->y + size/2 && y >= this->y - size/2;
}

void Square::draw()
{
    glColor3f(r, g, b);
    glRectf(x-size/2, y+size/2,
            x+size/2, y-size/2);
}

void Square::setColor(float r, float g, float b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}
