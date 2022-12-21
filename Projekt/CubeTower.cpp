//
// Created by emilj on 2022-12-18.
//

#include "CubeTower.h"

CubeTower::CubeTower() {
    addCube(0,0);
}

void CubeTower::addCube(double sizeX, double sizeY) {
    cubeTower.emplace_back(250, 400 - cubeTower.size() * 50,  sizeX, sizeY);
}

FixedCube &CubeTower::operator[](std::size_t i) {
    return cubeTower[i];
}

const FixedCube &CubeTower::operator[](std::size_t i) const {
    return cubeTower[i];
}

std::vector<FixedCube>::iterator CubeTower::top() {
    return cubeTower.end();
}

std::vector<FixedCube>::iterator CubeTower::bottom() {
    return cubeTower.begin();
}
