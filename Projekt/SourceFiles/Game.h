// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-12-21
// "kortfattat vad filen innehåller"


#ifndef PROJEKT_GAME_H
#define PROJEKT_GAME_H

#include <SFML/Audio.hpp>
#include "Cube.h"
#include "MovingCube.h"
#include "CubeTower.h"
#include "Menu.h"


class Game {
public:
    Game(int width, int height, const std::string& gameTitle, sf::ContextSettings settings);
    void run();
private:
    void initializeElements();
    void handleInputs();
    void updateObjects();
    void drawObjects();
    bool placeCube();
    void gameOver();
    void getHighScore();
    void updateHighScore();
    void placeCubeAnimations();
    void gameOverAnimation();
    void restartGame();

    //game objects
    sf::View view;
    sf::RenderWindow window;
    sf::Font font;
    sf::Text scoreText;
    Menu mainMenu;



    //entities
    CubeTower<Cube> cubeTower;
    MovingCube movingCube;
    Cube floorCube;

    //other
    sf::Vector2i mousePos;
    sf::Vector2f mouseWorldPos;
    int incrementCubeAnimationAmount = 0;
    bool incrementCubeAnimation = false;
    int zoomAmount = 0;
    float overHang = 0;
    int highScore = 0;
    bool paused = true;
    bool isGameOver = false;

    int score = 0;
};


#endif //PROJEKT_GAME_H
