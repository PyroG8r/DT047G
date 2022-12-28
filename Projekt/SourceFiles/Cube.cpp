//
// Created by emilj on 2022-12-17.
//

#include "Cube.h"



Cube::Cube(float sizeX, float sizeY) : sizeX(sizeX), sizeY(sizeY){
    details.resize(3);
    cube.setPointCount(6);
    cube.setFillColor(sf::Color(0, 255, 204));
    //cube.setOutlineColor(sf::Color(112, 112, 112));
    //cube.setOutlineThickness(3);

    cube.setOrigin(50,50);

    for(int i = 0; i < 3; i++){
        details[i].setPointCount(4);
        details[i].setOrigin(50,50);
    }
    details[0].setFillColor(sf::Color(170, 170, 170, 128));
    details[1].setFillColor(sf::Color(145, 145, 145, 128));
    details[2].setFillColor(sf::Color(130, 130, 130, 128));

    setPoints();
    setDetails();
}

const sf::ConvexShape Cube::getShape() {
    return cube;
}


sf::Vector2f Cube::getPos() {
    return cube.getPosition();
}
void Cube::setPos(sf::Vector2f pos) {
    cube.setPosition(pos);
    details[0].setPosition(pos);
    details[1].setPosition(pos);
    details[2].setPosition(pos);
}

void Cube::setPoints() {
    point1 = sf::Vector2f(50.f + sizeX - sizeY, 0.f - sizeX/2 - sizeY/2);
    point2 = sf::Vector2f( 100.f + sizeX, 25.f - sizeX/2);
    point3 = sf::Vector2f(100.f + sizeX, 75.f - sizeX/2);
    point4 = sf::Vector2f(50.f, 100.f);
    point5 = sf::Vector2f(0.f - sizeY, 75.f - sizeY/2);
    point6 = sf::Vector2f(0.f - sizeY, 25.f - sizeY/2);
    point7 = sf::Vector2f (50.f, 50.f);

    cube.setPoint(0, point1);
    cube.setPoint(1, point2);
    cube.setPoint(2, point3);
    cube.setPoint(3, point4);
    cube.setPoint(4, point5);
    cube.setPoint(5, point6);

}

void Cube::setDetails() {

    details[0].setPoint(0, point1);
    details[0].setPoint(1, point2);
    details[0].setPoint(2, point7);
    details[0].setPoint(3, point6);

    details[1].setPoint(0, point6);
    details[1].setPoint(1, point7);
    details[1].setPoint(2, point4);
    details[1].setPoint(3, point5);

    details[2].setPoint(0, point7);
    details[2].setPoint(1, point2);
    details[2].setPoint(2, point3);
    details[2].setPoint(3, point4);

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

void Cube::setSize(sf::Vector2f newSize){
    sizeX = newSize.x;
    sizeY = newSize.y;
    setPoints();
    setDetails();
}

double Cube::getSizeX() {
    return sizeX;
}

double Cube::getSizeY() {
    return sizeY;
}

void Cube::setColor(sf::Color color) {
    cube.setFillColor(color);
}

std::vector<sf::ConvexShape> Cube::getDetails() {
    return details;
}









