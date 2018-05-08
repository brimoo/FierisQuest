#include "Square.hpp"
#include "RgbImage.hpp"

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
    
    if (type->texture() != std::string(""))
        displayTexture();
}

void Square::setType(SquareType* type)
{
    this->type = type;
}

void Square::click()
{
    if (dynamic_cast<WallSquare*>(type))
        setType(new NormalSquare);
    else if (dynamic_cast<NormalSquare*>(type))
        setType(new WallSquare);
}

void Square::drag()
{
    if (dynamic_cast<NormalSquare*>(type))
        setType(new WallSquare);
}

SquareType* Square::getType()
{
    return type;
}

void Square::displayTexture()
{        
    glEnable(GL_TEXTURE_2D);
    
    RgbImage textureMap( type->texture().c_str() );
    
    glGenTextures(1, &type->texID);
    glBindTexture(GL_TEXTURE_2D, type->texID);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, 1, 1, GL_RGB,
                      GL_UNSIGNED_BYTE, textureMap.ImageData() );
    
    glBegin(GL_QUADS);
    float top = y+size/2;
    float bottom = -top;
    float right = x+size/2;
    float left = -right;
    
    glTexCoord2f(left, bottom);
    glTexCoord2f(left, top);
    glTexCoord2f(right, top);
    glTexCoord2f(right, bottom);
    glEnd();
    
    glDisable(GL_TEXTURE_2D);
}
