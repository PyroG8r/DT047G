//
// Created by emilj on 2022-12-12.
//

#ifndef LAB5_PLAYER_H
#define LAB5_PLAYER_H

#include "iostream"
#include <string>
#include <utility>

class Player {
public:
    Player() = default;
    Player(std::string name, double speed, double score):
    name(std::move(name)), speed(speed), score(score) { }

    std::string getName() const { return name; }

    //overloaded == operator for comparing name
    bool operator==(const Player &player) const{
        return name == player.name;
    }

    double getSpeed() const { return speed; }
    double getScore() const { return score; }
private:
    double speed;
    double score;

    std::string name;
};


#endif //LAB5_PLAYER_H
