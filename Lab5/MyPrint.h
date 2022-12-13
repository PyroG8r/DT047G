//
// Created by emilj on 2022-12-12.
//

#ifndef LAB5_MYPRINT_H
#define LAB5_MYPRINT_H


#include "Player.h"

class MyPrint {
public:
    
    //function call operator overloaded to print your class data members: name and parameters
    void operator()(Player player) {
        std::cout << "Name: " << player.name << std::endl;
        std::cout << "Speed: " << player.speed << std::endl;
        std::cout << "Score: " << player.score << std::endl;
    }

};


#endif //LAB5_MYPRINT_H
