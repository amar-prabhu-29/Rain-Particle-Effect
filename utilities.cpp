#include <GL/glut.h>
#include <stdlib.h>

void drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
        glVertex2d(x1, y1);
        glVertex2d(x2, y2);
    glEnd();
}

int myRandom(int lower, int upper) {
    return lower + (random() % (upper - lower + 1));
}