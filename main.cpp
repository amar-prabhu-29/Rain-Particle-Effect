#include <GL/glut.h>
#include "Drop.h"

void displayHandler();
void idleHandler();
void initGL();

const int dropCount = 700;
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
    
    for(int i=0 ; i<dropCount ; i++) {
        drop[i].show();
        drop[i].fall();
    }
    
    glFlush();
}

void idleHandler() {
    glutPostRedisplay();
}