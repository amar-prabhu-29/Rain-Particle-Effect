#include<GL/freeglut.h>
#include<math.h>
#include "utilities.h"
int starPosition[100][2];
bool called = false;
void drawSoil(){
    glColor3ub(155,118,83);
    glBegin(GL_POLYGON);
        glVertex2f(-100,-30);
        glVertex2f(-90,-35);
        glVertex2f(100,-30);
        glVertex2f(100,-100);
        glVertex2f(-100,-100);
    glEnd();
}

void drawNightSky(){
    glColor3ub(57, 32, 51);
    glBegin(GL_POLYGON);
        glVertex2f(-100,100);
        glVertex2f(100,100);
        glVertex2f(100,-30);
        glVertex2f(-100,-30);
    glEnd();
}

void drawStars(){
    glColor3ub(255, 255, 255);
    glPointSize(2);
    
    if(!called){
        called = true;
        for(int i=0;i<100;i++){
            starPosition[i][0] = myRandom(-100,100);
            starPosition[i][1] = myRandom(-20,100);
        }
    }
    glBegin(GL_POINTS);
        for(int i=0;i<100;i++){
            if(myRandom(0,1) != 0)
                glVertex2d(starPosition[i][0],starPosition[i][1]);
        }
    glEnd();
}

void drawRainySky(){
    glColor3ub(146, 186, 210);
    glBegin(GL_POLYGON);
        glVertex2f(-100,100);
        glVertex2f(100,100);
        glVertex2f(100,-30);
        glVertex2f(-100,-30);
    glEnd();
}

void drawMorningSky(){
    glColor3ub(205,249,255);
    glBegin(GL_POLYGON);
        glVertex2f(-100,100);
        glVertex2f(100,100);
        glVertex2f(100,-30);
        glVertex2f(-100,-30);
    glEnd();
}

void drawAfternoonSky(){
    glColor3ub(172,245,251);
    glBegin(GL_POLYGON);
        glVertex2f(-100,100);
        glVertex2f(100,100);
        glVertex2f(100,-30);
        glVertex2f(-100,-30);
    glEnd();
}

void drawEveningSky(){
    glColor3ub(117,213,227);
    glBegin(GL_POLYGON);
        glVertex2f(-100,100);
        glVertex2f(100,100);
        glVertex2f(100,-30);
        glVertex2f(-100,-30);
    glEnd();
}

void drawTankBackground(){
    glColor3ub(72,72,72);
    glBegin(GL_POLYGON);
        glVertex2f(-40,0);
        glVertex2f(-40,-50);
        glVertex2f(40,-50); 
        glVertex2f(40,0);
    glEnd();
}

void drawTankForeground(){
    glColor4f(1,1,1,0.5);
    glBegin(GL_POLYGON);
        glVertex2f(-40,0);
        glVertex2f(-40,-50);
        glVertex2f(40,-50); 
        glVertex2f(40,0);
    glEnd();
}

