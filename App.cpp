#include "App.hpp"
#include "App.hpp"
#include "Board.hpp"
#include "AlgorithmRunner.hpp"
#include <vector>

App::App(const char* label, int x, int y, int w, int h)
    : GlutApp(label, x, y, w, h)
    , mx(0)
    , my(0)
    , board(new Board(20))
    , algoRunner(new AlgorithmRunner(board))
{ }

App::~App()
{
    delete board;
    delete algoRunner;
}

void App::draw()
{
    // Clear the screen && set up transformation stack
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    algoRunner->next();
    board->draw();
    
    // Display
    glutSwapBuffers();
}

void App::mouseDown(float x, float y)
{
    // Update app state
    mx = x;
    my = y;

    board->click(x, y);
    
    // Redraw the scene
    redraw();
}

void App::mouseDrag(float x, float y)
{
    // Update app state
    mx = x;
    my = y;

    if (!algoRunner->isRunning())
        board->drag(x, y);
    // Redraw the scene
    redraw();
}

void App::keyPress(unsigned char key)
{
    std::string algo = "";
    switch (key) {
    case 27: // ESC
        // Exit the app when Esc key is pressed
        exit(0);
        break;

    case ' ':
        board->reset();
        algoRunner->reset();
        redraw();
        break;

    case '1':
        algo = "A*";
        break;

    case '2':
        algo = "Dijkstra";
        break;

    case '3':
        algo = "BFS";
        break;

    case '4':
        algo = "DFS";
        break;

    case '\n':
        if (algo != std::string(""))
            algoRunner->setAlgorithm(algo);
        break;
    }  
}
