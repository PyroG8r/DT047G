//
// Created by emilj on 2022-12-17.
//

#ifndef PROJEKT_CUBE_H
#define PROJEKT_CUBE_H

#include <SFML/Graphics.hpp>



class Cube : public sf::ConvexShape {
public:
    explicit Cube(float sizeX, float sizeY);

    void draw(sf::RenderWindow &window);

    void setCubePosition(const sf::Vector2f& position);


    void setSize(const sf::Vector2f& newSize);
    double getSizeX() const;
    double getSizeY() const;

    void increaseXAxis();
    void increaseYAxis();

    void decreaseXAxis();
    void decreaseYAxis();

    sf::Vector2f point5;
    sf::Vector2f point6;
private:
    void setPoints();
    void setFacePoints();
    std::vector<sf::ConvexShape> faces;
    float sizeX;
    float sizeY;

    sf::Vector2f point1;
    sf::Vector2f point2;
    sf::Vector2f point3;
    sf::Vector2f point4;
    sf::Vector2f point7;

};


#endif //PROJEKT_CUBE_H
