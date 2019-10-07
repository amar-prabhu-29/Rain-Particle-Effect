#include <GL/freeglut.h>
#include <iostream>

void drawLine(float x1, float y1, float x2, float y2) {
    glColor3f(0,0,0.54); 
    glBegin(GL_LINES);
        glVertex2d(x1, y1);
        glVertex2d(x2, y2);
    glEnd();
}

void drawRectangle(float Xmin, float Ymin, float Xmax, float Ymax) {
    glColor3ub(149, 148, 139);
    glBegin(GL_POLYGON);
            glVertex2d(Xmin, Ymax);
            glVertex2d(Xmax, Ymax);
            glVertex2d(Xmax, Ymin);
            glVertex2d(Xmin, Ymin);  
    glEnd();
}

int myRandom(int lower, int upper) {
    return lower + (rand() % (upper - lower + 1));
}