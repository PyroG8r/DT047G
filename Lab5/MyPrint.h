//
// Created by emilj on 2022-12-12.
//

#ifndef LAB5_MYPRINT_H
#define LAB5_MYPRINT_H


#include "Player.h"

class MyPrint {
public:
    MyPrint() = default;
    //function call operator overloaded to print your class data members: name and parameters
    void operator()(Player& player) const {
        std::cout << "Name: " << player.getName() << "\n";
        std::cout << "Speed: " << player.getSpeed() << "\n";
        std::cout << "Score: " << player.getScore() << "\n\n";
    }

};


#endif //LAB5_MYPRINT_H
