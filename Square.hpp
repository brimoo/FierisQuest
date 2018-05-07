#ifndef Square_hpp
#define Square_hpp

class Square {
protected:
    float x;
    float y;
    float size;

    float r;
    float g;
    float b;

public:
    Square(float x, float y, float size,
           float r=1, float g=1, float b=1);
    virtual ~Square() {}
    bool contains(float x, float y);
    virtual void draw();
    void setColor(float r, float g, float b);
};

#endif // Square_hpp
