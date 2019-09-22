#include "Drop.h"
#include "utilities.h"
#include <iostream>

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
        resetDrop();
    }
}

void Drop::show() {
    drawLine(x, y, x, y+height);
}

void Drop::resetDrop() {
    x = myRandom(-100, 100);
    y = myRandom(100, 500);
    yVelocity = myRandom(30, 40) / 1000.0;
}

bool Drop::isInsideTank() {
    // -40 and 40 are the left and right edges of the tank. -50 is bottom of the tank
    if(x > -40 && x < 40 && y < -50) {
        return true;
    }

    return false;
}