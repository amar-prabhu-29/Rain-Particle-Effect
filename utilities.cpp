#include <GL/glut.h>
#include <stdlib.h>

void drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
        glVertex2d(x1, y1);
        glVertex2d(x2, y2);
    glEnd();
}

void drawRectangle(float Xmin, float Ymin, float Xmax, float Ymax) {
    glBegin(GL_LINE_LOOP);
            glVertex2d(Xmin, Ymax);
            glVertex2d(Xmax, Ymax);
            glVertex2d(Xmax, Ymin);
            glVertex2d(Xmin, Ymin);  
    glEnd();
}

int myRandom(int lower, int upper) {
    return lower + (random() % (upper - lower + 1));
}