//
// Created by emilj on 2022-12-18.
//

#include <cmath>
#include <iostream>
#include "MovingCube.h"
#include "cmath"
#include "Constants.h"

// problem with initializing dirUpDown
MovingCube::MovingCube(float sizeX, float sizeY)
: Cube(sizeX, sizeY), 
dirUpDown(DOWN), 
dirLeftRight(LEFT), 
path(ALONG_X), 
startHeight(0), 
startOffsetX(0), 
startOffsetY(0) 
{
    setCubePosition(sf::Vector2f(SCREEN_WIDTH + 50,CUBE_HEIGHT));
}


void MovingCube::move() {
    sf::Vector2f pos = getPosition();
    if (pos.x > SCREEN_WIDTH + 100 || pos.x < -100) {
        toggleDirUpDown();
        toggleDirLeftRight();
    }
    if (dirLeftRight == LEFT && dirUpDown == DOWN){
        setCubePosition(sf::Vector2f(pos.x - 2 * speed, pos.y + 1 * speed));
        path = ALONG_X;
    }
    if (dirLeftRight == LEFT && dirUpDown == UP) {
        setCubePosition(sf::Vector2f(pos.x - 2 * speed, pos.y - 1 * speed));
        path = ALONG_Y;
    }
    if (dirLeftRight == RIGHT && dirUpDown == DOWN) {
        setCubePosition(sf::Vector2f(pos.x + 2 * speed, pos.y + 1 * speed));
        path = ALONG_Y;
    }
    if (dirLeftRight == RIGHT && dirUpDown == UP) {
        setCubePosition(sf::Vector2f(pos.x + 2 * speed, pos.y - 1 * speed));
        path = ALONG_X;
    }
}

void MovingCube::toggleDirLeftRight() {
    dirLeftRight = !dirLeftRight;
}

void MovingCube::toggleDirUpDown() {
    dirUpDown = !dirUpDown;
}

float MovingCube::placeCube(const FixedCube& TopCube) {
    sf::Vector2f topCubePos = TopCube.getPosition();
    sf::Vector2f thisCubePos = getPosition();

    sf::Vector2f towerPoint6 = topCubePos + TopCube.point6;
    sf::Vector2f movingPoint5 = thisCubePos + point5;

    float deltaX = movingPoint5.x - towerPoint6.x;
    float deltaY = movingPoint5.y - towerPoint6.y;

    float overHang = std::sqrt((float)pow(deltaX, 2) + (float)pow(deltaY,2));



    std::cout << towerPoint6.x << " : " << towerPoint6.y << "\n"
              << movingPoint5.x << " : " << movingPoint5.y << "\n"
             << deltaX << " : " << deltaY << "\n"
             << "overhang: " << overHang << "\n";




    resetCubeState(deltaX, deltaY);

    return overHang;
}



void MovingCube::resetCubeState(float deltaX, float deltaY) {
    if (path == ALONG_X){
        //placed before tower
        if (deltaX > 0){
            startOffsetX += deltaX;
            startOffsetY += deltaY;
        }
        setCubePosition(sf::Vector2f(-50 + startOffsetX, -startHeight++ * CUBE_HEIGHT + startOffsetY));

        if (dirLeftRight == LEFT) toggleDirLeftRight();
    }
    //path along y
    else {
        //placed before tower
        if (deltaX < 0){
            startOffsetX += deltaX;
            startOffsetY += deltaY;
        }
        setCubePosition(sf::Vector2f(SCREEN_WIDTH+50 + startOffsetX, -startHeight++ * CUBE_HEIGHT + startOffsetY));


        if (dirLeftRight == RIGHT) toggleDirLeftRight();
    }

    dirUpDown = DOWN;
}

bool MovingCube::getMovingPath() const {
    return path;
}







/*



 void Cube::increaseXAxis() {
    sizeX = sizeX + 0.1;
    setPoints();
}

void Cube::increaseYAxis() {
    sizeY = sizeY + 0.1;
    setPoints();
}

void Cube::decreaseXAxis() {
    (sizeX < -50) ? : sizeX = sizeX - 0.1;
    setPoints();
}

void Cube::decreaseYAxis() {
    (sizeY < -50) ? : sizeY = sizeY - 0.1;
    setPoints();
}

void Cube::setSize(sf::Vector2f size){
    sizeX = size.x;
    sizeY = size.y;
}








 double deltaX = 0;
    double deltaY = 0;
    std::cout << thisCubePos.x << " : " << topCubePos.x << "\n";
    if (dirLeftRight == LEFT){
        deltaX = movingPoint5.x - towerPoint6.x;
        deltaY = movingPoint5.y - towerPoint6.y;
    }
    else if (dirLeftRight == RIGHT) {
        deltaX = movingPoint5.x - towerPoint6.x;
        deltaY = movingPoint5.y - towerPoint6.y;
    }



*/




