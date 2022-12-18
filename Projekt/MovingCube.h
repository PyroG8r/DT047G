//
// Created by emilj on 2022-12-18.
//

#ifndef PROJEKT_MOVINGCUBE_H
#define PROJEKT_MOVINGCUBE_H


#include "Cube.h"

class MovingCube : public Cube {
public:
    MovingCube(float posX, float posY, double sizeX, double sizeY);

    void toggleDir();

    void move();
private:
    enum Direction {LEFT, RIGHT};
    bool direction;
    float offset = 10;
};


#endif //PROJEKT_MOVINGCUBE_H
