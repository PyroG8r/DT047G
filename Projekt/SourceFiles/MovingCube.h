//
// Created by emilj on 2022-12-18.
//

#ifndef PROJEKT_MOVINGCUBE_H
#define PROJEKT_MOVINGCUBE_H


#include "Cube.h"
#include "FixedCube.h"

class MovingCube : public Cube {
public:
    MovingCube(double sizeX, double sizeY);

    double placeCube(FixedCube onTopOf);
    bool getMovingPath();

    void move();
private:
    void toggleDirUpDown();
    void toggleDirLeftRight();
    void resetCubeState(double deltaX, double deltaY);

    enum dirUpDown {UP, DOWN};
    enum dirLeftRight {LEFT, RIGHT};
    enum path {ALONG_X, ALONG_Y};
    int startHeight;
    bool dirUpDown;
    bool dirLeftRight;
    bool path;
    float speed = 1;
};


#endif //PROJEKT_MOVINGCUBE_H
