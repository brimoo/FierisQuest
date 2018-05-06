#ifndef RECT_H
#define RECT_H
#include <iostream>
#include "Vec.hpp"

class Rect{

    public:

        float x;
        float y;
        float height; 
        float width;
    

        Rect(){
            x = 0;
            y = 0;
            width = 0;
            height = 0;

        }

        Rect(float x, float y, float width, float height){
            this -> x = x;
            this -> y = y;
            this -> height = height;
            this -> width = width;
        }




        bool contains(Vec point){
            if (point.getX() >= x && point.getX() <= x + width && point.getY() <= y && point.getY() >= y - height){
                return true;
            }
            else {
                return false;
            }
        }

       

};
#endif
