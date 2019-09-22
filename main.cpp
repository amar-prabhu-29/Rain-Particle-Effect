#include <iostream>
#include <GL/glut.h>
#include "Drop.h"
#include "utilities.h"

void displayHandler();
void idleHandler();
void initGL();

const int dropCount = 700;
int intersectedCount = 0;
float scanline = -50;           //Initially, scanline is set to bottom of the tank.
Drop drop[dropCount];

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Rain Particle Effect");

    glutDisplayFunc(displayHandler);
    glutIdleFunc(idleHandler);

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
    glColor3ub(235, 244, 250);
    
    //Raindrops
    glPointSize(4);
    for(int i=0 ; i<dropCount ; i++) {
        if(drop[i].isInsideTank()) {
            intersectedCount++;
            drop[i].resetDrop();
            std::cout << intersectedCount << "\n";
            continue;
        }

        drop[i].show();
        drop[i].fall();
    }

    drawLine(-25, -50, -25, -100);      //Left support
    drawLine(25, -50, 25, -100);         //Right support

    //Tank
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
    int numLines = intersectedCount / 10;
    for(int i=1 ; i<=numLines*100 ; i++) {
        if(scanline+i/100.0 > 0) {
            //0 is the Ymax of the tank. If current scanline (scanline+i) is greater than tank top, then stop the loop
            break;
        }
        drawLine(-40, scanline + i/100.0, 40, scanline + i/100.0);
    }
    
    glFlush();
}

void idleHandler() {
    glutPostRedisplay();
}