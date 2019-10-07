#include <iostream>
#include <GL/freeglut.h>
#include "Drop.h"
#include "utilities.h"
#include "sunDisplay.h"
#include "scenery.h"
#include<math.h>

void displayHandler();
void idleHandler();
void initGL();
void sunDisplay();
void processNormalKeys(unsigned char key, int x, int y);

const int dropCount = 700;
int intersectedCount = 0;
float scanline = -50;           //Initially, scanline is set to bottom of the tank.
int numLines;
bool rainCycle = true;

int checkTank = 0;
Drop drop[dropCount];

int main(int argc, char *argv[]) {
    
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Rain Particle Effect");

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
    glEnable( GL_BLEND ); 
    glClearColor(0.0,0.0,0.0,0.0);
    
    glutDisplayFunc(displayHandler);
    glutIdleFunc(idleHandler);
    glutKeyboardFunc(processNormalKeys);

    initGL();
    glutMainLoop();

    return 0;
}

void initGL() {
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(-100, 100, -100, 100);
}


void displayHandler() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawSoil();
    drawRainySky();
    drawTankBackground();

    glColor3ub(235, 244, 250);
    //Raindrops
    glPointSize(4);
    for(int i=0 ; i<dropCount ; i++) {
        if(drop[i].isInsideTank()) {
            intersectedCount++;
            drop[i].resetDrop();
            //std::cout << intersectedCount << "\n";
            continue;
        }

        drop[i].show();
        drop[i].fall();
    }

    glColor3ub(112,90,62);
    glBegin(GL_POLYGON);
        glVertex2f(-25,-50);
        glVertex2f(-25,-100);
        glVertex2f(25,-100);
        glVertex2f(25,-50);
    glEnd();

    //Tank
    glColor3f(0,0,0);
    glBegin(GL_LINE_STRIP);
        glVertex2d(-40, 0);
        glVertex2d(-40, -50);
        glVertex2d(40, -50);
        glVertex2d(40, 0);
    glEnd();

    //middle support
    float Xmin = -25, Ymax = -50;
    for(int i=0 ; i<3 ; i++) {

        //left middle support   
             
        drawRectangle(Xmin + 5, Ymax - 3 - (41/3.0), Xmin + 22.5, Ymax - 3);            
        Xmin += 22.5;
        
        //right middle support
        drawRectangle(Xmin + 5, Ymax - 3 - (41/3.0), Xmin + 22.5, Ymax - 3);            
        Ymax = Ymax - 3 - (41/3.0);

        Xmin = -25;
    }
    //Fill the tank 
    numLines = intersectedCount / 10;
    for(int i=1 ; i<=numLines*100 ; i++) {
        if(scanline+i/100.0 > 0) {
            //0 is the Ymax of the tank. If current scanline (scanline+i) is greater than tank top, then stop the loop
            break;
        }
        //std::cout<<scanline;
        drawLine(-40, scanline + i/100.0, 40, scanline + i/100.0);
    }

    drawTankForeground();

    

    glFlush();
}

void idleHandler() {
    glutPostRedisplay();
}

void processNormalKeys(unsigned char key, int x, int y){
    if(key == 's' && rainCycle == true){
        rainCycle = false;
        setTankLevel(numLines);
        glutDisplayFunc(sunDisplay);
    }
    if(key == 'r' && rainCycle == false){
        rainCycle = true;
        intersectedCount = getTankLevel()*10;
        glutDisplayFunc(displayHandler);
    }
}
void sunDisplay(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    drawSoil();
    determineSky();
    drawTankBackground();
    if(checkTank == 0){
        checkTank = 1;
        setTankLevel(numLines);
    }
    displayCelestialObject();
    drawTank();
    fillTank();
    evaporate();
    moveSun();
    drawTankForeground();
    

    glFlush();
}