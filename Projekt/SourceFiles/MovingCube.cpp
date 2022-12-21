//
// Created by emilj on 2022-12-18.
//

#include <iostream>
#include "MovingCube.h"
                                                                                            // problem with initializing dirUpDown
MovingCube::MovingCube(double sizeX, double sizeY) : Cube(sizeX, sizeY), dirUpDown(DOWN), dirLeftRight(LEFT), startHeight(0){
    setPos(sf::Vector2f(550,100));
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
    else if (dirLeftRight == LEFT && dirUpDown == UP) {
        setPos(sf::Vector2f(pos.x - 2 * speed, pos.y - 1 * speed));
    }
    else if (dirLeftRight == RIGHT && dirUpDown == DOWN) {
        setPos(sf::Vector2f(pos.x + 2 * speed, pos.y + 1 * speed));
    }
    else if (dirLeftRight == RIGHT && dirUpDown == UP) {
        setPos(sf::Vector2f(pos.x + 2 * speed, pos.y - 1 * speed));
    }
}

void MovingCube::toggleDirLeftRight() {
    dirLeftRight = !dirLeftRight;
}

void MovingCube::toggleDirUpDown() {
    dirUpDown = !dirUpDown;
}

void MovingCube::placeCube() {
    toggleDirLeftRight();

    if (dirLeftRight){
        setPos(sf::Vector2f(-50, -startHeight++ * 50));
    }
    else {
        setPos(sf::Vector2f(550, -startHeight++ * 50));
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




