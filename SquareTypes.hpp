#ifndef SquareTypes_hpp
#define SquareTypes_hpp

#include <vector>
#include <string>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

struct SquareType {
    GLuint texID;
    
    virtual ~SquareType() {}
    
    virtual std::string texture() { return ""; };
    virtual bool isTraverseable() { return true; }
    // {r, g, b}
    virtual std::vector<float> color() = 0;
};

struct NormalSquare : public SquareType {
    // White
    std::vector<float> color() { return {1, 1, 1}; }
};

struct ExpandingSquare : public SquareType {
    // Dark Blue
    std::vector<float> color() { return {0, 0, 1}; }
};

struct TraversedSquare : public SquareType {
    // Light Blue
    std::vector<float> color() { return {0.47, 0.81, 0.99}; }
};

struct WallSquare : public SquareType {
    bool isTraverseable() { return false; }
    // Gray
    std::vector<float> color() { return {0.25, 0.25, 0.25}; }
};

struct StartSquare : public SquareType {
    // White
    std::vector<float> color() { return {1, 1, 1}; }

    // Guy Fieri's Face
    std::string texture() { return "bitmaps/fieri.bmp"; }
};

struct EndSquare : public SquareType {
    // White
    std::vector<float> color() { return {1, 1, 1}; }

    // Burger
    std::string texture() { return "bitmaps/burger.bmp"; }
};

struct PathSquare : public SquareType {
    // Green
    std::vector<float> color() { return {0, 1, 0}; }
};

#endif // SquareTypes_hpp
