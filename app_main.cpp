#include "App.hpp"
#include <cstdlib>

int main(int argc, char* argv[])
{
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    
    int board_size = 15;

    if (argc == 2)
        board_size = atoi(argv[1]);

    // Instantiate a new App
    App* myApp = new App("Fieri's Quest", 100, 100, 800, 800, board_size);
    
    // Start the app
    myApp->run();
}
