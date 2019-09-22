#include "Drop.h"
#include "utilities.h"

Drop::Drop() {
    //gluOrtho2D(-100, 100, -100, 100)
    x = myRandom(-100, 100);
    y = myRandom(100, 500);
    yVelocity = myRandom(30, 40) / 1000.0;
    height = 5;
}

void Drop::fall() {
    y -= yVelocity;

    if(y < -100) {
        y = myRandom(100, 500);
    }
}

void Drop::show() {
    drawLine(x, y, x, y+height);
}