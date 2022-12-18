//
// Created by emilj on 2022-12-18.
//

#ifndef PROJEKT_CUBETOWER_H
#define PROJEKT_CUBETOWER_H


#include "Cube.h"

class CubeTower : public Cube {
public:
    CubeTower();
private:
    std::vector<Cube> cubeTower;
};


#endif //PROJEKT_CUBETOWER_H
