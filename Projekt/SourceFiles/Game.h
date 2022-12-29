// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-12-21
// "kortfattat vad filen innehåller"


#ifndef PROJEKT_GAME_H
#define PROJEKT_GAME_H

#include <SFML/Audio.hpp>
#include "Cube.h"
#include "MovingCube.h"
#include "FixedCube.h"
#include "CubeTower.h"
#include "Menu.h"
#include "Sound.h"


class Game {
public:
    Game(int width, int height, const std::string& gameTitle);
    void run();
private:
    void initializeView();
    void handleInputs();
    void updateObjects();
    void drawObjects();
    bool placeCube();
    void gameOver();
    void getHighScore();
    void updateHighScore();

    //game objects
    sf::ContextSettings settings;
    sf::View view;
    sf::RenderWindow window;
    sf::Font font;
    sf::Text scoreText;
    Menu mainMenu;

    //entities
    CubeTower cubeTower;
    MovingCube movingCube;
    //FixedCube floorCube;

    //other
    sf::Vector2i mousePos;
    sf::Vector2f mouseWorldPos;
    int score = 0;
    int highScore;
    bool paused = true;

    //sounds
    const std::string placeCubeSound_path = "Sounds/placeCube.wav";
    const std::string perfectPlaceCubeSound_path = "Sounds/perfect-place.wav";
    const std::string missPlaceCubeSound_path = "Sounds/miss-place.wav";
    const std::string gameOverSound_path = "Sounds/game-over.wav";

};


#endif //PROJEKT_GAME_H
