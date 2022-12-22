// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-12-21
// "kortfattat vad filen innehåller"


#ifndef PROJEKT_GAME_H
#define PROJEKT_GAME_H

#include "Cube.h"
#include "MovingCube.h"
#include "FixedCube.h"
#include "CubeTower.h"

class Game {
public:
    Game(int width, int height, const std::string& gameTitle);
    void run();
private:
    void initializeView();
    void handleInputs();
    void updateObjects();
    void drawObjects();
    void placeCube();

    //game objects
    sf::ContextSettings settings;
    sf::View view;
    sf::RenderWindow window;

    //entities
    CubeTower cubeTower;
    MovingCube movingCube;

    //other
    sf::Vector2i mousePos;
    sf::Vector2f mouseWorldPos;
};


#endif //PROJEKT_GAME_H
