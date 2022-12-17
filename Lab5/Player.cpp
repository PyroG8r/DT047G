//
// Created by emilj on 2022-12-12.
//

#include "Player.h"

Player::Player(std::string name, double speed, double score) : name(name), speed(speed), score(score){

}

Player::Player() {

}

bool Player::operator==(const Player &player) const {
    return name == player.name;
}
