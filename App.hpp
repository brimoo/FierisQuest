#ifndef App_hpp
#define App_hpp

#include "GlutApp.hpp"
#include "Board.hpp"
#include <vector>

class App : public GlutApp {
    // Maintain app state here
    float mx;
    float my;

    Board* board;

public:
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);
    ~App();
    
    // These are the events we want to handle
    void draw();
    void keyPress(unsigned char key);
    void mouseDown(float x, float y);
    void mouseDrag(float x, float y);
};

#endif // App_hpp
