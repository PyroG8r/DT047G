//
// Created by emilj on 2022-12-18.
//

#include "MovingCube.h"

MovingCube::MovingCube(float posX, float posY, double sizeX, double sizeY) : Cube(sizeX, sizeY){
    setPos(sf::Vector2f(posX, posY));
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




