//
// Created by emilj on 2022-12-19.
//

#include "FixedCube.h"

FixedCube::FixedCube(float posX, float posY, float sizeX, float sizeY) : Cube(sizeX, sizeY) {
    setCubePosition(sf::Vector2f(posX, posY));
}
