// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-12-21
// "kortfattat vad filen innehåller"


#include <iostream>
#include <cmath>
#include <fstream>
#include "Game.h"
#include "Constants.h"

Game::Game(const int width, const int height, const std::string& gameTitle)
: window(sf::VideoMode(500, 500), gameTitle),
  movingCube(0, 0),
  //floorCube(250, 500, 450, 450),
  view(sf::FloatRect(0, 0, 500.f, 500.f))
{
    window.setFramerateLimit(60);
    settings.antialiasingLevel = 8;
    getHighScore();
    //floorCube.setColor(sf::Color(167, 194, 175));

    /*sf::SoundBuffer soundBuffer;
    soundBuffer.loadFromFile("Sounds/placeCube.wav");
    sf::Sound sound(soundBuffer);*/


}

void Game::run() {
    initializeView();

    while (window.isOpen()) {
        handleInputs();

        updateObjects();
        drawObjects();
    }
}

void Game::initializeView() {

    //sf::View view(sf::FloatRect(0, 0, 500.f, 500.f));


    //view.setSize(window.getSize().x, window.getSize().y);
    //view.zoom(0.5f);


    if(!font.loadFromFile("Fonts/Roboto-Bold.ttf")){
        std::cerr << "Error loading font" << std::endl;
    }

    scoreText.setFont(font);
    scoreText.setString(std::to_string(score));
    scoreText.setCharacterSize(50);
    scoreText.setFillColor(sf::Color(64, 64, 64));

    sf::FloatRect textRect = scoreText.getLocalBounds();
    scoreText.setOrigin(textRect.left + textRect.width / 2.0f,
                   textRect.top + textRect.height / 2.0f);


    scoreText.setPosition(int(SCREEN_WIDTH/2), 50);

}

void Game::handleInputs() {
    mousePos = sf::Mouse::getPosition(window);
    mouseWorldPos = window.mapPixelToCoords(mousePos, view);

    //main event loop
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space && !paused) {
                if(placeCube()){
                    score++;
                    scoreText.setString(std::to_string(score)); // Update the text object's string
                    //Sound placeCubeSound(placeCubeSound_path);
                    //placeCubeSound.play();


                }
                else{
                    gameOver();
                }
            }
            // if key escape is pressed, show menu
            if (event.key.code == sf::Keyboard::Escape) {
                if(paused){
                    mainMenu.showMenu(false);
                    paused = false;
                }
                else{
                    mainMenu.showMenu(true);
                    paused = true;
                }
            }
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (mainMenu.isPlayButtonPressed(mousePos)) {
                mainMenu.showMenu(false);
                paused = false;
            }
            if (mainMenu.isExitButtonPressed(mousePos)){
                window.close();
            }
        }
    }
}


void Game::updateObjects() {

    if(!paused){
        movingCube.move();
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
        movingCube.setPos(mouseWorldPos);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        movingCube.increaseLeft();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        movingCube.decreaseLeft();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        movingCube.increaseRight();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        movingCube.decreaseRight();
    }
}
void Game::drawObjects() {

    window.clear(sf::Color(223, 207, 165));

    window.setView(view);

    // print all cubes in tower using std::for_each
    //window.draw(floorCube.getShape());
    std::for_each(cubeTower.bottom(), cubeTower.top(), [this](Cube &cube){
        window.draw(cube.getShape());
        window.draw(cube.getDetails()[0]);
        window.draw(cube.getDetails()[1]);
        window.draw(cube.getDetails()[2]);
    });

    window.draw(movingCube.getShape());

    window.draw(movingCube.getDetails()[0]);
    window.draw(movingCube.getDetails()[1]);
    window.draw(movingCube.getDetails()[2]);

    //reset the view to default view to draw hud elements
    window.setView(window.getDefaultView());

    if(!paused) {window.draw(scoreText);}
    mainMenu.draw(window);

    window.display();

}

bool Game::placeCube() {
    //move camera 1 cube height up
    view.move(0,- CUBE_HEIGHT);

    float overHang;
    FixedCube topCube = cubeTower.topCube();
    sf::Vector2f placedPos(movingCube.getPos());
    sf::Vector2f newSize(movingCube.getSizeX(),movingCube.getSizeY());


    overHang = movingCube.placeCube(topCube);

    //moving along x placed "under" tower
    if (placedPos.x < topCube.getPos().x && !movingCube.getMovingPath()){
        newSize.x -= overHang;
        placedPos = topCube.getPos();
        placedPos.y = placedPos.y - CUBE_HEIGHT;
    }
    //moving along x placed "above" tower
    else if (placedPos.x > topCube.getPos().x && !movingCube.getMovingPath()){
        newSize.x -= overHang;
    }
    //moving along y placed "above" tower
    else if (placedPos.x < topCube.getPos().x && movingCube.getMovingPath()){
        newSize.y -= overHang;
    }
    //moving along y placed "under" tower
    else if (placedPos.x > topCube.getPos().x && movingCube.getMovingPath()){
        newSize.y -= overHang;
        placedPos = topCube.getPos();
        placedPos.y = placedPos.y - CUBE_HEIGHT;
    }

    if (placedPos.x == topCube.getPos().x){

    }

    if (newSize.x < -CUBE_SIZE || newSize.y < -CUBE_SIZE ){
        return false;
    }
    cubeTower.addCube(newSize, placedPos);
    movingCube.setSize(sf::Vector2f(newSize.x,newSize.y));
    return true;
}

void Game::gameOver() {
    updateHighScore();

    paused = true;
    mainMenu.showMenu(true);
    view.zoom(1 + float(score) / 5);
}

void Game::getHighScore() {
    //read highScore from file with error handling
    std::ifstream highScoreFile;
    highScoreFile.open("highScore.txt");
    if (highScoreFile.is_open()){
        highScoreFile >> highScore;
        highScoreFile.close();
    }
    else{
        std::cout << "Failed to open highScore.txt";
    }
}

void Game::updateHighScore() {
    if (score > highScore){
        highScore = score;
        std::ofstream highScoreFile;
        highScoreFile.open("highScore.txt");
        highScoreFile << highScore;
        highScoreFile.close();
        mainMenu.updateHighScore(highScore);
    }
}




/*std::cout << "Place Pos X " <<  placedPos.x << " Y " << placedPos.y << "\n";
std::cout << "Size X " <<  movingCube.getSizeX() << " Y " << movingCube.getSizeY() << "\n";
std::cout << "Size X " <<  newSize.x << " Y " << newSize.y << "\n";
//newSize.x = ceil(newSize.x);
//newSize.y = ceil(newSize.y);
//std::cout << "Size X " <<  newSize.x << " Y " << newSize.y << "\n";*/
