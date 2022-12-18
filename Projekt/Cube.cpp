//
// Created by emilj on 2022-12-17.
//

#include "Cube.h"



Cube::Cube(double sizeX, double sizeY, float posX, float posY) : sizeX(sizeX * 100), sizeY(sizeY * 100), posX(posX), posY(posY){
    cube.setPointCount(6);
    cube.setFillColor(sf::Color(35, 166, 135));
    cube.setOutlineColor(sf::Color(91, 38, 135));
    cube.setOutlineThickness(5);
    cube.setPosition(200,200);
    setPoints();
}

sf::ConvexShape Cube::getCube() {
    return cube;
}

void Cube::setPosX(float posX) {
    this->posX = posX;
    setPoints();
}

void Cube::setPosY(float posY) {
    this->posY = posY;
    setPoints();
}

/**
 *           1
 *          /  \
 *       /          \
 * 6  /               \  2
 *   |                  |
 *   |                  |
 * 5  \                /  3
 *        \        /
 *           \ /
 *          4
 */



void Cube::setPoints() {
    point1 = sf::Vector2f(50.f + posX + sizeX - sizeY, 0.f + posY - sizeX/2 - sizeY/2);
    point2 = sf::Vector2f( 100.f + posX + sizeX, 25.f + posY - sizeX/2);
    point3 = sf::Vector2f(100.f + posX + sizeX, 75.f + posY - sizeX/2);
    point4 = sf::Vector2f(50.f + posX, 100.f + posY);
    point5 = sf::Vector2f(0.f + posX - sizeY, 75.f + posY - sizeY/2);
    point6 = sf::Vector2f(0.f + posX - sizeY, 25.f + posY - sizeY/2);
    cube.setPoint(0, point1);
    cube.setPoint(1, point2);
    cube.setPoint(2, point3);
    cube.setPoint(3, point4);
    cube.setPoint(4, point5);
    cube.setPoint(5, point6);
}

void Cube::move() {
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

void Cube::toggleDir() {
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

void Cube::increaseRight() {
    sizeX = sizeX + 0.1;
    setPoints();
}

void Cube::increaseLeft() {
    sizeY = sizeY + 0.1;
    setPoints();
}

void Cube::decreaseRight() {
    sizeX = sizeX - 0.1;
    setPoints();
}

void Cube::decreaseLeft() {
    sizeY = sizeY - 0.1;
    setPoints();
}


