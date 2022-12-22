//
// Created by emilj on 2022-12-18.
//

#include <iostream>
#include "MovingCube.h"
#include "cmath"
                                                                                            // problem with initializing dirUpDown
MovingCube::MovingCube(double sizeX, double sizeY) : Cube(sizeX, sizeY), dirUpDown(DOWN), dirLeftRight(LEFT), startHeight(0){
    setPos(sf::Vector2f(550,50));
}


void MovingCube::move() {
    sf::Vector2f pos = getPos();
    if (pos.x > 550 || pos.x < -50) {
        toggleDirUpDown();
        toggleDirLeftRight();
    }
    if (dirLeftRight == LEFT && dirUpDown == DOWN){
        setPos(sf::Vector2f(pos.x - 2 * speed, pos.y + 1 * speed));
    }
     if (dirLeftRight == LEFT && dirUpDown == UP) {
        setPos(sf::Vector2f(pos.x - 2 * speed, pos.y - 1 * speed));
    }
     if (dirLeftRight == RIGHT && dirUpDown == DOWN) {
        setPos(sf::Vector2f(pos.x + 2 * speed, pos.y + 1 * speed));
    }
     if (dirLeftRight == RIGHT && dirUpDown == UP) {
        setPos(sf::Vector2f(pos.x + 2 * speed, pos.y - 1 * speed));
    }
}

void MovingCube::toggleDirLeftRight() {
    dirLeftRight = !dirLeftRight;
}

void MovingCube::toggleDirUpDown() {
    dirUpDown = !dirUpDown;
}

double MovingCube::placeCube(FixedCube TopCube) {
    sf::Vector2f topCubePos = TopCube.getPos();
    sf::Vector2f thisCubePos = getPos();

    sf::Vector2f towerForwardPoint = topCubePos;
    sf::Vector2f towerBackwardPoint = topCubePos;

    sf::Vector2f movingForwardPoint = thisCubePos;
    sf::Vector2f movingBackwardPoint = getShape().getPoint(1);

    double deltaX = movingForwardPoint.x - towerForwardPoint.x;
    double deltaY = movingForwardPoint.y + 50 - towerForwardPoint.y;



    double overHang = sqrt(pow(deltaX, 2) + pow(deltaY,2));



    std::cout << towerForwardPoint.x << " : " << towerForwardPoint.y << "\n"
              << movingForwardPoint.x << " : " << movingForwardPoint.y << "\n"
             << deltaX << " : " << deltaY << "\n"
             << overHang;


    resetCubePos();

    return overHang;

    /*
    std::vector<sf::Vector2f> topCubePoints(6);
    for (int i = 0; i < 5; i++) {
        topCubePoints[i] = TopCube.getPoint(i);
    }*/

}

void MovingCube::resetCubePos() {
    if ((dirLeftRight == LEFT && dirUpDown == DOWN) || (dirLeftRight == RIGHT && dirUpDown == UP)){
        setPos(sf::Vector2f(-50, -startHeight++ * 50));
        if (dirLeftRight == LEFT) toggleDirLeftRight();
    }
    else {
        setPos(sf::Vector2f(550, -startHeight++ * 50));
        if (dirLeftRight == RIGHT) toggleDirLeftRight();
    }

    if (dirUpDown == UP) {
        toggleDirUpDown();
    }
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





*/




