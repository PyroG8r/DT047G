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
    std::string getName() const { return name; }

    //overloaded == operator for comparing name
    bool operator==(const Player &player) const;

    double getSpeed() const { return speed; }
    double getScore() const { return score; }
private:
    double speed;
    double score;

    std::string name;
};


#endif //LAB5_PLAYER_H
