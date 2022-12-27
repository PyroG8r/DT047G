//
// Created by emilj on 2022-12-17.
//

#ifndef PROJEKT_CUBE_H
#define PROJEKT_CUBE_H

#include <SFML/Graphics.hpp>


class Cube {
public:
    explicit Cube(float sizeX, float sizeY);
    
    const sf::ConvexShape getShape();

    void setPos(sf::Vector2f);
    sf::Vector2f getPos();


    void setSize(sf::Vector2f);

    void increaseRight();
    void increaseLeft();

    void decreaseRight();
    void decreaseLeft();

    void setColor(sf::Color color);

    double getSizeX();
    double getSizeY();

    sf::Vector2f point2;
    sf::Vector2f point3;
    sf::Vector2f point5;
    sf::Vector2f point6;
private:
    void setPoints();

    sf::ConvexShape cube;
    float sizeX;
    float sizeY;

    sf::Vector2f point1;
    sf::Vector2f point4;

};


#endif //PROJEKT_CUBE_H
