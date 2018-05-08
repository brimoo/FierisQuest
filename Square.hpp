#ifndef Square_hpp
#define Square_hpp

#include "SquareTypes.hpp"

class Square {
    float x;
    float y;
    float size;

    SquareType* type;
    
public:
    Square(float x, float y, float size);

    ~Square();
    
    bool contains(float x, float y);

    void draw();

    void setType(SquareType* type);

    void click();
    
    SquareType* getType();
};

#endif // Square_hpp
