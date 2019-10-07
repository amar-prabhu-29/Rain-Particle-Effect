#include "sunDisplay.h"
#include <GL/freeglut.h>
#include "utilities.h"
#include<iostream>
#include<math.h>
#include "scenery.h"

int tankLevel;
int counter = 0;
int tankFilled = 0;

//Sun Coordinates
int sunCounter = 0;
float x=-101,y=60;
bool dayCycle = true;
float angleInit=0.0,angleFinal=360.0;

void setTankLevel(int level){
    tankLevel = level;
}
int getTankLevel(){
    return tankLevel;
}

void moveSun(){
    if(sunCounter % 100 == 0){
        sunCounter = 0;
        x=(x)*cos(-0.00523599)-(y+100)*sin(-0.00523599);
        y=-100+(x)*sin(-0.00523599)+(y+100)*cos(-0.00523599);
    }
    sunCounter+=1;
    if(dayCycle && x>100){
        dayCycle = false;
        x=-101;
        angleInit = 0.0;
        angleFinal = 360.0; 
    }
    if(!dayCycle && x>100){
        dayCycle = true;
        x=-101;
        angleInit = 0.0;
        angleFinal = 360.0;
    }
}

void displayCelestialObject(){
    if(dayCycle){
        glColor3ub(252, 212, 64);
    }
    else{
        glColor3ub(255,255,255);
    }
    float i = 0.0f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x,y);
        for(i = angleInit; i <= angleFinal; i++)
            glVertex2f(10*cos(3.141592 * i / 180.0) + x, 10*sin(3.141592  * i / 180.0) + y);
    glEnd();
    if(!dayCycle){
        glColor3ub(57, 32, 51);
        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(x+6,y);
            for(i = angleInit; i <= angleFinal; i++)
                glVertex2f(10*cos(3.141592 * i / 180.0) + x+10, 10*sin(3.141592  * i / 180.0) + y);
        glEnd();
    }
}

void drawTank(){
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
}

void fillTank(){
    int level = -50 + tankLevel;
    for(int i=-50;i<=level;i++){
        for(int j=1;j<=10;j++){
            drawLine(-40,i+j/10.0,40,i+j/10.0);
        }   
    }
}

void evaporate(){
    if(counter % 1000 == 0 && x>=-40 && x<=40 && dayCycle){
        tankLevel-=1;
    }
    counter+=1;
}

void determineSky(){
    if(dayCycle){
        if(x<=-40){
            drawMorningSky();
        }
        else if(x>=-40 && x<=40){
            drawAfternoonSky();
        }
        else{
            drawEveningSky();
        }
    }
    else{
        drawNightSky();
    }

}