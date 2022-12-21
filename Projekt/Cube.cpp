//
// Created by emilj on 2022-12-17.
//

#include "Cube.h"



Cube::Cube(double sizeX, double sizeY) : sizeX(sizeX), sizeY(sizeY){
    cube.setPointCount(6);
    cube.setFillColor(sf::Color(157, 158, 157));
    cube.setOutlineColor(sf::Color(112, 112, 112));

    //set the thickness of the outline
    cube.setOutlineThickness(3);

    
    cube.setOrigin(50,50);
    setPoints();
}

sf::ConvexShape Cube::getShape() {
    return cube;
}


sf::Vector2f Cube::getPos() {
    return cube.getPosition();
}
void Cube::setPos(sf::Vector2f pos) {
    cube.setPosition(pos);

}

void Cube::setPoints() {
    point1 = sf::Vector2f(50.f + sizeX - sizeY, 0.f - sizeX/2 - sizeY/2);
    point2 = sf::Vector2f( 100.f + sizeX, 25.f - sizeX/2);
    point3 = sf::Vector2f(100.f + sizeX, 75.f - sizeX/2);
    point4 = sf::Vector2f(50.f, 100.f);
    point5 = sf::Vector2f(0.f - sizeY, 75.f - sizeY/2);
    point6 = sf::Vector2f(0.f - sizeY, 25.f - sizeY/2);

    cube.setPoint(0, point1);
    cube.setPoint(1, point2);
    cube.setPoint(2, point3);
    cube.setPoint(3, point4);
    cube.setPoint(4, point5);
    cube.setPoint(5, point6);
    
}





void Cube::increaseRight() {
    sizeX = sizeX + 1;
    setPoints();
}

void Cube::increaseLeft() {
    sizeY = sizeY + 1;
    setPoints();
}

void Cube::decreaseRight() {
    (sizeX < -50) ? : sizeX = sizeX - 1;
    setPoints();
}

void Cube::decreaseLeft() {
    (sizeY < -50) ? : sizeY = sizeY - 1;
    setPoints();
}

void Cube::setSize(sf::Vector2f size){
    sizeX = size.x;
    sizeY = size.y;
}

double Cube::getSizeX() {
    return sizeX;
}

double Cube::getSizeY() {
    return sizeY;
}








