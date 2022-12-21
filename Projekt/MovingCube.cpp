//
// Created by emilj on 2022-12-18.
//

#include <iostream>
#include "MovingCube.h"
                                                                                            // problem with initializing direction
MovingCube::MovingCube(double sizeX, double sizeY) : Cube(sizeX, sizeY), direction(){
    setPos(sf::Vector2f(550,100));
}


void MovingCube::move() {
    sf::Vector2f pos = getPos();
    if (direction){
        setPos(sf::Vector2f(pos.x + 2 * speed, pos.y + 1 * speed));
    }
    else {
        setPos(sf::Vector2f(pos.x - 2 * speed, pos.y + 1 * speed));
    }
}

void MovingCube::toggleDir() {
    direction = !direction;
}

void MovingCube::placeCube() {
    toggleDir();
    sf::Vector2f pos = getPos();

    // fixa så att kuben tpaar till pos relativt till fönstret...........

    (direction) ? setPos(sf::Vector2f(-50, pos.y-50)) : setPos(sf::Vector2f(550, pos.y-50));
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




