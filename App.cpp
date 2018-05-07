#include "App.hpp"
#include "App.hpp"
#include "Board.hpp"
#include <vector>

App::App(const char* label, int x, int y, int w, int h)
    : GlutApp(label, x, y, w, h)
    , mx(0)
    , my(0)
    , board(new Board(20))
{ }

App::~App()
{
    delete board;
}

void App::draw()
{
    // Clear the screen && set up transformation stack
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    board->draw();
    
    // Display
    glutSwapBuffers();
}

void App::mouseDown(float x, float y)
{
    // Update app state
    mx = x;
    my = y;

    // Redraw the scene
    redraw();
}

void App::mouseDrag(float x, float y)
{
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    redraw();
}

void App::keyPress(unsigned char key)
{
    if (key == 27){
        // Exit the app when Esc key is pressed
        exit(0);
    }
}
