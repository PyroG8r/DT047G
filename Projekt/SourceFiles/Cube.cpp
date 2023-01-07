//
// Created by emilj on 2022-12-17.
//

#include <iostream>
#include "Cube.h"



Cube::Cube(float sizeX, float sizeY) : sizeX(sizeX), sizeY(sizeY), sf::ConvexShape(6){
    faces.resize(3);

    setFillColor(sf::Color(36, 213, 151));
    setOrigin(50,50);

    for(auto& face: faces){
        face.setPointCount(4);
        face.setOrigin(50,50);
    }
    faces[0].setFillColor(sf::Color(170, 170, 170, 100));
    faces[1].setFillColor(sf::Color(145, 145, 145, 100));
    faces[2].setFillColor(sf::Color(130, 130, 130, 100));


    setPoints();
}


void Cube::draw(sf::RenderWindow &window) {
    window.draw(*this);
    for(const auto& face: faces){
        window.draw(face);
    }


}


void Cube::setCubePosition(const sf::Vector2f &position) {
    sf::ConvexShape::setPosition(position);
    for(auto& face: faces){
        face.setPosition(position);
    }
}

void Cube::setPoints() {
    point1 = sf::Vector2f(50.f + sizeX - sizeY, 0.f - sizeX/2 - sizeY/2);
    point2 = sf::Vector2f( 100.f + sizeX, 25.f - sizeX/2);
    point3 = sf::Vector2f(100.f + sizeX, 75.f - sizeX/2);
    point4 = sf::Vector2f(50.f, 100.f);
    point5 = sf::Vector2f(0.f - sizeY, 75.f - sizeY/2);
    point6 = sf::Vector2f(0.f - sizeY, 25.f - sizeY/2);
    point7 = sf::Vector2f (50.f, 50.f);

    setPoint(0, point1);
    setPoint(1, point2);
    setPoint(2, point3);
    setPoint(3, point4);
    setPoint(4, point5);
    setPoint(5, point6);

    setFacePoints();
}

void Cube::setFacePoints() {
    //top face
    faces[0].setPoint(0, point1);
    faces[0].setPoint(1, point2);
    faces[0].setPoint(2, point7);
    faces[0].setPoint(3, point6);

    //right face
    faces[2].setPoint(0, point7);
    faces[2].setPoint(1, point2);
    faces[2].setPoint(2, point3);
    faces[2].setPoint(3, point4);

    //left face
    faces[1].setPoint(0, point6);
    faces[1].setPoint(1, point7);
    faces[1].setPoint(2, point4);
    faces[1].setPoint(3, point5);
}

void Cube::increaseXAxis() {
    sizeX = sizeX + 1;
    setPoints();
}

void Cube::increaseYAxis() {
    sizeY = sizeY + 1;
    setPoints();
}

void Cube::decreaseXAxis() {
    (sizeX < -50) ? : sizeX = sizeX - 1;
    setPoints();
}

void Cube::decreaseYAxis() {
    (sizeY < -50) ? : sizeY = sizeY - 1;
    setPoints();
}

void Cube::setSize(const sf::Vector2f& newSize){
    sizeX = newSize.x;
    sizeY = newSize.y;
    setPoints();
}

sf::Vector2f Cube::getSize() const {
    return {sizeX, sizeY};
}
















