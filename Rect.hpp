#ifndef Rect_hpp
#define Rect_hpp

struct Rect{
    float x;
    float y;
    float height; 
    float width;
    
    Rect(float x=0, float y=0, float width=0, float height=0);
    bool contains(float x, float y);
};

#endif // Rect_hpp
