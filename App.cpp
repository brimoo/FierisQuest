#include "App.h"
#include "Rect.h"
#include <vector>

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0;
    
    next.push_back(new Rect(.5,-.6,.3,.5 ));    
    prev.push_back(new Rect(-.5,-.6,.3,.5));
}

void App::draw() {

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set background color to black


    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Set Color




    glColor3f(.3,.5,.6);
    glLineWidth(2);
    glBegin(GL_LINES);

    glVertex2f(-.3, -.7);
    glVertex2f(-.4, -.8);

    glVertex2f(-.4, -.8);
    glVertex2f(-.3, -.9);

    glVertex2f(-.3, -.9);
    glVertex2f(-.3, -.7);

    glColor3f(.3,.5,.6);
    glLineWidth(5);
    glBegin(GL_LINES);

    glVertex2f(.3, -.7);
    glVertex2f(.4, -.8);

    glVertex2f(.4, -.8);
    glVertex2f(.3, -.9);

    glVertex2f(.3, -.9);
    glVertex2f(.3, -.7);



    glEnd();

    glBegin(GL_LINES);
    
    glVertex2f(0,-1);
    glVertex2f(0, 1);

    glEnd();


    glColor3f(0,0,1);
    glRectf(next[0] -> x, next[0] -> y, next[0] -> x - next[0] -> width, next[0] -> y - next[0] -> height);
    glRectf(prev[0] -> x, prev[0] -> y, prev[0] -> x + prev[0] -> width, prev[0] -> y - prev[0] ->height);

    

    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}



void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;

    // Redraw the scene
    redraw();
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    //if (contains(Vec(mx, my))){
    //
    //}
    redraw();
}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        exit(0);
    }
}
