//
// Created by emilj on 2022-12-18.
//

#ifndef PROJEKT_CUBETOWER_H
#define PROJEKT_CUBETOWER_H

#include "FixedCube.h"

class CubeTower {
public:
    CubeTower();
    void addCube(double sizeX, double sizeY);


    FixedCube& operator[](std::size_t i);
    const FixedCube& operator[](std::size_t i) const;

    std::vector<FixedCube>::iterator top();
    std::vector<FixedCube>::iterator bottom();


private:
    std::vector<FixedCube> cubeTower;
};


#endif //PROJEKT_CUBETOWER_H
