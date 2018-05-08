#include "App.hpp"
#include <iostream>

// Singleton required for animation control, can't be inside of class itself
static App* singleton;

void animate(int value)
{
    if (!singleton->isRunning() || singleton->isPaused())
        return;

    singleton->redraw();
    glutTimerFunc(singleton->getSpeed(), animate, value);
}

App::App(const char* label, int x, int y, int w, int h)
    : GlutApp(label, x, y, w, h)
    , mx(0)
    , my(0)
    , board(new Board(20))
    , algoRunner(new AlgorithmRunner(board))
    , selected_algo("")
    , paused(false)
{
    singleton = this;
    printIntro();
}

App::~App()
{
    delete board;
    delete algoRunner;
}

void App::printIntro()
{
    std::cout << std::endl;
    std::cout << "Welcome to Fieri's Quest!" << std::endl;
    std::cout << "Please select start and goal squares with left click." << std::endl;
    std::cout << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << "Controls:" << std::endl;
    std::cout << "1 \t Select A*" << std::endl;
    std::cout << "2 \t Select Dijkstra" << std::endl;
    std::cout << "3 \t Select Breadth First Search" << std::endl;
    std::cout << "4 \t Select Depth First Search" << std::endl;
    std::cout << "Enter \t Run Selected Algorithm" << std::endl;
    std::cout << "+ \t Increase Simulation Speed" << std::endl;
    std::cout << "- \t Decrease Simulation Speed" << std::endl;
    std::cout << "p \t Pause Simulation" << std::endl;
    std::cout << "Space \t Reset Simulation" << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << std::endl;
}

void App::draw()
{
    // Clear the screen && set up transformation stack
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Run next iteration of pathing algorithm and redraw board
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

    // Don't allow new walls to be drawn if the algorithm's running
    if (!algoRunner->isRunning())
        board->drag(x, y);
    
    // Redraw the scene
    redraw();
}

void App::keyPress(unsigned char key)
{
    switch (key) {
    case 27: // ESC
        // Exit the app when Esc key is pressed
        std::cout << "Goodbye!" << std::endl;
        exit(0);
        break;

        // Spacebar resets the board and algorithm
    case ' ': // SPACE
        board->reset();
        algoRunner->reset();
        redraw();
        std::cout << "Simulation Reset" << std::endl;
        break;

        // Number keys select algorithm to use
    case '1':
        selected_algo = "A*";
        std::cout << "Selected: A*" << std::endl;
        break;

    case '2':
        selected_algo = "Dijkstra";
        std::cout << "Selected: Dijkstra" << std::endl;
        break;

    case '3':
        selected_algo = "BFS";
        std::cout << "Selected: Breath First Search" << std::endl;
        break;

    case '4':
        selected_algo = "DFS";
        std::cout << "Selected: Depth First Search" << std::endl;
        break;

        // Enter runs the selected algorithm if one is chosen
    case 13: // ENTER
        if (selected_algo != std::string("") && board->goalsChosen()){
            std::cout << "Running " << selected_algo << "..." << std::endl;
            algoRunner->setAlgorithm(selected_algo);
            animate(0);
        }
        break;

        // Decrease animation speed
    case '-':
        if(animationSpeed < 100) {
            animationSpeed += 5;
            std::cout << "Animation Delay: " << animationSpeed << "ms" << std::endl;
        }
        break;

        // Increase animation speed
    case '=':
        if(animationSpeed > 0) {
            animationSpeed -= 5;
            std::cout << "Animation Delay: " << animationSpeed << "ms" << std::endl;
        }
        break;

        // Pause animation
    case 'p':
        if (paused) {
            paused = false;
            std::cout << "Resumed" << std::endl;
            animate(0);
        }
        else {
            paused = true;
            std::cout << "Paused" << std::endl;
        }
        break;
    }  
}

bool App::isRunning()
{
    return algoRunner->isRunning();
}

int App::getSpeed()
{
    return animationSpeed;
}

bool App::isPaused()
{
    return paused;
}
