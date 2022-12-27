#include <SFML/Window.hpp>
#include <iostream>
#include "Game.h"


int main() {
    srand(time(0));
    const int width = 500;
    const int height = 500;
    const std::string gameTitle = "Stacker";
    Game game(width, height, gameTitle);
    game.run();


        /*std::cout << movingCube.getSizeX() << "\n";
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            movingCube.toggleDirLeftRight();
        }*/

    return 0;
}

