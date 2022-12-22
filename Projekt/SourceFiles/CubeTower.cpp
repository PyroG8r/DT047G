//
// Created by emilj on 2022-12-18.
//

#include "CubeTower.h"

CubeTower::CubeTower() : towerHeight(0) {
    addCube(sf::Vector2f(0,0), sf::Vector2f(250,250));
}

void CubeTower::addCube(sf::Vector2f size, sf::Vector2f pos) {
    cubeTower.emplace_back(pos.x, pos.y - towerHeight++ * 50,  size.x, size.y);


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

FixedCube CubeTower::topCube() {
    return cubeTower.back();
}
