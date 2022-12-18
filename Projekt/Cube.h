//
// Created by emilj on 2022-12-17.
//

#ifndef PROJEKT_CUBE_H
#define PROJEKT_CUBE_H

#include <SFML/Graphics.hpp>


class Cube {
public:
    explicit Cube(double sizeX, double sizeY, float posX, float posY);
    sf::ConvexShape getCube();
    void setPosX(float posX);
    void setPosY(float posY);

    void setPoints();
    void move();

    void toggleDir();

    void increaseRight();
    void increaseLeft();

    void decreaseRight();
    void decreaseLeft();

private:
    enum Direction {LEFT, RIGHT};
    sf::ConvexShape cube;
    double sizeX;
    double sizeY;
    float posX;
    float posY;

    bool direction;
    float offset = 10;


    sf::Vector2f point1;
    sf::Vector2f point2;
    sf::Vector2f point3;
    sf::Vector2f point4;
    sf::Vector2f point5;
    sf::Vector2f point6;

};


#endif //PROJEKT_CUBE_H
