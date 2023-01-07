#include <SFML/Window.hpp>
#include <iostream>
#include "Game.h"


int main() {
    srand(time(0));
    const int width = 500;
    const int height = 500;
    const std::string gameTitle = "Stacker";
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    Game game(width, height, gameTitle, settings);
    game.run();
    return 0;
}

