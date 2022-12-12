//
// Created by emilj on 2022-12-12.
//

#ifndef LAB5_PLAYER_H
#define LAB5_PLAYER_H

#include "iostream"
#include <string>

class Player {
public:
    Player();
    Player(std::string basicString, double speed, double score);
private:
    std::string name;
    double speed;
    double score;

};


#endif //LAB5_PLAYER_H
