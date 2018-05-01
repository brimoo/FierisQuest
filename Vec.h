#ifndef VEC_H
#define VEC_H
#include <iostream>

class Vec{
    float x;
    float y;

    public:
    Vec(){
        x = 0;
        y = 0;
    }
    Vec(float x, float y){
        this -> x = x;
        this -> y = y;
    }

    void add(Vec other){
        setX(getX() + other.getX());
        setY(getY() + other.getY());
    }

    void setX(float x){
        this -> x = x;
    }

    void setY(float y){
        this -> y = y;
    }

    float getX()const{
        return this -> x;
    }

    float getY()const{
        return this -> y;
    }

    void print() {
        std::cout << "(" << getX() << ", " << getY() << ")" << std::endl;
    }
};
#endif

