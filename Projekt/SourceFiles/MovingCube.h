//
// Created by emilj on 2022-12-18.
//

#ifndef PROJEKT_MOVINGCUBE_H
#define PROJEKT_MOVINGCUBE_H


#include "Cube.h"

class MovingCube : public Cube {
public:
    MovingCube(double sizeX, double sizeY);

    void placeCube();

    void move();
private:
    void toggleDirUpDown();
    void toggleDirLeftRight();

    enum dirUpDown {UP, DOWN};
    enum dirLeftRight {LEFT, RIGHT};
    int startHeight;
    bool dirUpDown;
    bool dirLeftRight;
    float speed = 1;
};


#endif //PROJEKT_MOVINGCUBE_H
