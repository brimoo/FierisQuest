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

    
    if (type->texture() != std::string("")) {
        displayTexture();
    }
    else {
    glRectf(x-size/2, y+size/2,
            x+size/2, y-size/2);
    }
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
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
    RgbImage textureMap( type->texture().c_str() );
    
    glGenTextures(1, &type->texID);
    glBindTexture(GL_TEXTURE_2D, type->texID);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, textureMap.GetNumCols(), textureMap.GetNumRows(),
            GL_RGB, GL_UNSIGNED_BYTE, textureMap.ImageData() );
    
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
    glBegin(GL_QUADS);

    glTexCoord2f(1, 0);
    glVertex2f(x-size/2, y-size/2);

    glTexCoord2f(1, 1);
    glVertex2f(x-size/2, y+size/2);

    glTexCoord2f(0, 1);
    glVertex2f(x+size/2, y+size/2);

    glTexCoord2f(0, 0);
    glVertex2f(x+size/2, y-size/2);

    glEnd();
    
    glDisable(GL_TEXTURE_2D);
}
