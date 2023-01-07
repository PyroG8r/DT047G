//
// Created by emilj on 2022-12-18.
//

#include "CubeTower.h"
#include "Constants.h"

CubeTower::CubeTower() {
    addCube(sf::Vector2f(0,0), sf::Vector2f(SCREEN_WIDTH/2,SCREEN_WIDTH/2));
}

void CubeTower::addCube(sf::Vector2f size, sf::Vector2f pos) {
    cubeTower.emplace_back(pos.x, pos.y,  size.x, size.y); // - towerHeight++ * 50

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

FixedCube& CubeTower::topCube() {
    return cubeTower.back();
}

size_t CubeTower::getSize() {
    return cubeTower.size();
}

void CubeTower::reset() {
    cubeTower.clear();
    addCube(sf::Vector2f(0,0), sf::Vector2f(SCREEN_WIDTH/2,SCREEN_WIDTH/2));
}
