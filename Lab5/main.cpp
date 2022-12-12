#include <iostream>
#include <vector>
#include "Player.h"

int main() {
    // Create a Player array
    Player players[5];
    
    // fill the array with players using a for loop with the names: Emil, Ruben, Isak, Jonatan, Jimmy
    // use random numbers for the speed and score
    for(int i = 0; i < 5; i++) {
        std::string name;
        if (i == 0) name = "Emil";
        if (i == 1) name = "Ruben";
        if (i == 2) name = "Isak";
        if (i == 3) name = "Jonatan";
        if (i == 4) name = "Jimmy";
        players[i] = Player(name, rand() % 100, rand() % 100);
    }
    
    

    return 0;
}
