//
// Created by emilj on 2022-12-18.
//

#include "MovingCube.h"

MovingCube::MovingCube(float posX, float posY, double sizeX, double sizeY) : Cube(sizeX, sizeY){
    getCube().setPosition(posX, posY);
}

/*
void MovingCube::move() {

    if (direction == RIGHT){
        posX = posX + (0.5 / offset);
        posY = posY + (0.25 / offset);
    }
    if (direction == LEFT){
        posX = posX - (0.5 / offset);
        posY = posY + (0.25 / offset);
    }
    setPoints();
}

void MovingCube::toggleDir() {
    posY = 0;
    if (direction == RIGHT){
        posX = 500;
        direction = LEFT;
    }
        //if the cube is moving left, it will now move right
    else if (direction == LEFT){
        posX = -100;
        direction = RIGHT;
    }
}
*/




