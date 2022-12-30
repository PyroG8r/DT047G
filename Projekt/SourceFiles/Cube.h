//
// Created by emilj on 2022-12-17.
//

#ifndef PROJEKT_CUBE_H
#define PROJEKT_CUBE_H

#include <SFML/Graphics.hpp>



class Cube {
public:
    /**
     * @brief Creates a cube with a given size
     * @param sizeX The size of the cube in the x-axis
     * @param sizeY The size of the cube in the y-axis
     * @details ...
     * 
    */
    explicit Cube(float sizeX, float sizeY);
    
    const sf::ConvexShape getShape();
    std::vector<sf::ConvexShape> getDetails();

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
    void setDetails();
    std::vector<sf::ConvexShape> details;
    sf::ConvexShape cube;
    float sizeX;
    float sizeY;

    sf::Vector2f point1;
    sf::Vector2f point4;
    sf::Vector2f point7;

};


#endif //PROJEKT_CUBE_H
