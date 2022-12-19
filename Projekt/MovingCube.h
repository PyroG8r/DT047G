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
    bool direction;
    float speed = 1;
};


#endif //PROJEKT_MOVINGCUBE_H
