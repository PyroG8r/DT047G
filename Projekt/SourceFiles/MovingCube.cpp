//
// Created by emilj on 2022-12-18.
//

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
    setPos(sf::Vector2f(SCREEN_WIDTH + 50,CUBE_HEIGHT));
}


void MovingCube::move() {
    sf::Vector2f pos = getPos();
    if (pos.x > SCREEN_WIDTH + 100 || pos.x < -100) {
        toggleDirUpDown();
        toggleDirLeftRight();
    }
    if (dirLeftRight == LEFT && dirUpDown == DOWN){
        setPos(sf::Vector2f(pos.x - 2 * speed, pos.y + 1 * speed));
        path = ALONG_X;
    }
    if (dirLeftRight == LEFT && dirUpDown == UP) {
        setPos(sf::Vector2f(pos.x - 2 * speed, pos.y - 1 * speed));
        path = ALONG_Y;
    }
    if (dirLeftRight == RIGHT && dirUpDown == DOWN) {
        setPos(sf::Vector2f(pos.x + 2 * speed, pos.y + 1 * speed));
        path = ALONG_Y;
    }
    if (dirLeftRight == RIGHT && dirUpDown == UP) {
        setPos(sf::Vector2f(pos.x + 2 * speed, pos.y - 1 * speed));
        path = ALONG_X;
    }
}

void MovingCube::toggleDirLeftRight() {
    dirLeftRight = !dirLeftRight;
}

void MovingCube::toggleDirUpDown() {
    dirUpDown = !dirUpDown;
}

float MovingCube::placeCube(FixedCube TopCube) {
    sf::Vector2f topCubePos = TopCube.getPos();
    sf::Vector2f thisCubePos = getPos();

    sf::Vector2f towerPoint6 = topCubePos + TopCube.point6;
    sf::Vector2f movingPoint5 = thisCubePos + point5;

    float deltaX = movingPoint5.x - towerPoint6.x;
    float deltaY = movingPoint5.y - towerPoint6.y;

    float overHang = sqrt(pow(deltaX, 2) + pow(deltaY,2));



    std::cout << towerPoint6.x << " : " << towerPoint6.y << "\n"
              << movingPoint5.x << " : " << movingPoint5.y << "\n"
             << deltaX << " : " << deltaY << "\n"
             << "overhang: " << overHang << "\n";




    resetCubeState(deltaX, deltaY);

    return overHang;

    /*
    std::vector<sf::Vector2f> topCubePoints(6);
    for (int i = 0; i < 5; i++) {
        topCubePoints[i] = TopCube.getPoint(i);
    }*/

}



void MovingCube::resetCubeState(float deltaX, float deltaY) {
    if (path == ALONG_X){
        //placed before tower
        if (deltaX > 0){
            startOffsetX += deltaX;
            startOffsetY += deltaY;
        }
        setPos(sf::Vector2f(-50 + startOffsetX, -startHeight++ * CUBE_HEIGHT + startOffsetY));

        if (dirLeftRight == LEFT) toggleDirLeftRight();
    }
    //path along y
    else {
        //placed before tower
        if (deltaX < 0){
            startOffsetX += deltaX;
            startOffsetY += deltaY;
        }
        setPos(sf::Vector2f(SCREEN_WIDTH+50 + startOffsetX, -startHeight++ * CUBE_HEIGHT + startOffsetY));


        if (dirLeftRight == RIGHT) toggleDirLeftRight();
    }

    dirUpDown = DOWN;
    std::cout << "resetPos: X " << getPos().x << " Y " << getPos().y << "\n";
}

bool MovingCube::getMovingPath() {
    return path;
}







/*



 void Cube::increaseRight() {
    sizeX = sizeX + 0.1;
    setPoints();
}

void Cube::increaseLeft() {
    sizeY = sizeY + 0.1;
    setPoints();
}

void Cube::decreaseRight() {
    (sizeX < -50) ? : sizeX = sizeX - 0.1;
    setPoints();
}

void Cube::decreaseLeft() {
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




