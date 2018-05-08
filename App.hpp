#ifndef App_hpp
#define App_hpp

#include "GlutApp.hpp"
#include "Board.hpp"
#include "AlgorithmRunner.hpp"
#include <vector>

class App : public GlutApp {
    // Maintain app state here
    float mx;
    float my;
    int animationSpeed = 30;

    Board* board;
    AlgorithmRunner* algoRunner;
    std::string selected_algo;
    
public:
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);
    ~App();
    
    // These are the events we want to handle
    void draw();
    void idle();
    void keyPress(unsigned char key);
    void mouseDown(float x, float y);
    void mouseDrag(float x, float y);
    bool isRunning();
    int  getSpeed();
};

#endif // App_hpp
