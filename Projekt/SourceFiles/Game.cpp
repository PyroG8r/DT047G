// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-12-21
// "kortfattat vad filen innehåller"


#include <iostream>
#include <fstream>
#include "Game.h"
#include "Constants.h"

Game::Game(const int width, const int height, const std::string& gameTitle)
: window(sf::VideoMode(width, height), gameTitle),
  movingCube(0, 0),
  floorCube(250, 500, 330, 330),
  view(sf::FloatRect(0, 0, 500.f, 500.f))
{
    window.setFramerateLimit(60);
    settings.antialiasingLevel = 0;
    floorCube.setFillColor(sf::Color(167, 194, 175));


}

void Game::run() {
    initializeElements();

    while (window.isOpen()) {
        handleInputs();

        updateObjects();
        drawObjects();
    }
}

void Game::initializeElements() {
    getHighScore();

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
                if (isGameOver){
                    restartGame();
                }
                else if(placeCube()){
                    score++;
                    scoreText.setString(std::to_string(score)); // Update the text object's string
                    //Sound placeCubeSound(placeCubeSound_path);
                    //placeCubeSound.play();
                }
                else{
                    gameOver();
                }
            }
            // if key escape is pressed, show pauseMenu
            if (event.key.code == sf::Keyboard::Escape && !isGameOver) {
                if(paused){
                    mainMenu.showPauseMenu(false);
                    paused = false;
                }
                else{
                    mainMenu.showPauseMenu(true);
                    paused = true;
                }
            }
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (mainMenu.isPlayButtonPressed(mousePos)) {
                mainMenu.showPauseMenu(false);
                paused = false;
            }
            else if (mainMenu.isExitButtonPressed(mousePos)){
                window.close();
            }
            else if (mainMenu.isRestartButtonPressed(mousePos)){
                restartGame();
            }
        }
    }
}


void Game::updateObjects() {

    if(!paused){
        movingCube.move();
    }
    placeCubeAnimations();
    gameOverAnimation();



    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
        movingCube.setCubePosition(mouseWorldPos);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        movingCube.increaseYAxis();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        movingCube.decreaseYAxis();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        movingCube.increaseXAxis();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        movingCube.decreaseXAxis();
    }
}

void Game::placeCubeAnimations() {
    if (incrementCubeAnimation){
        if (incrementCubeAnimationAmount < 10){

            if(movingCube.getMovingPath()) {
                movingCube.increaseXAxis();
                cubeTower.topCube().increaseXAxis();
            }
            else {
                movingCube.increaseYAxis();
                cubeTower.topCube().increaseYAxis();
            }

            incrementCubeAnimationAmount++;
        }
        else{
            incrementCubeAnimation = false;
            incrementCubeAnimationAmount = 0;
        }
    }
}

void Game::gameOverAnimation() {
    if(isGameOver){
        if (zoomAmount < 60) {
            view.zoom(1 + float(score) / 1000);
            view.move(0,score / 2.5);
            zoomAmount++;
        }
    }
}

void Game::drawObjects() {
    window.clear(sf::Color(223, 207, 165));
    window.setView(view);

    floorCube.draw(window);
    // print all cubes in tower using std::for_each
    std::for_each(cubeTower.bottom(), cubeTower.top(), [this](Cube &cube){
        cube.draw(window);
    });
    if(!isGameOver) { movingCube.draw(window); }

    //reset the view to default view to draw hud elements
    window.setView(window.getDefaultView());

    window.draw(scoreText);
    mainMenu.draw(window);

    window.display();
}

bool Game::placeCube() {
    FixedCube topCube = cubeTower.topCube();
    sf::Vector2f placedPos(movingCube.getPosition());
    sf::Vector2f newSize(movingCube.getSizeX(),movingCube.getSizeY());

    overHang = movingCube.placeCube(topCube);

    //moving along x placed "under" tower
    if (!movingCube.getMovingPath() && placedPos.x < topCube.getPosition().x){
        newSize.x -= overHang;
        placedPos = topCube.getPosition();
        placedPos.y = placedPos.y - CUBE_HEIGHT;
    }
    //moving along x placed "above" tower
    else if (!movingCube.getMovingPath() && placedPos.x > topCube.getPosition().x){
        newSize.x -= overHang;
    }
    //moving along y placed "above" tower
    else if (movingCube.getMovingPath() && placedPos.x < topCube.getPosition().x){
        newSize.y -= overHang;
    }
    //moving along y placed "under" tower
    else if (movingCube.getMovingPath() && placedPos.x > topCube.getPosition().x){
        newSize.y -= overHang;
        placedPos = topCube.getPosition();
        placedPos.y = placedPos.y - CUBE_HEIGHT;
    }

    //cube is placed perfect
    else if (placedPos.x == topCube.getPosition().x){
        incrementCubeAnimation = true;
    }

    //failes to place cube
    if (newSize.x < -CUBE_SIZE || newSize.y < -CUBE_SIZE ){
        return false;
    }
    //move camera 1 cube height up
    view.move(0,- CUBE_HEIGHT);
    cubeTower.addCube(newSize, placedPos);
    movingCube.setSize(newSize);
    return true;
}

void Game::gameOver() {
    isGameOver = true;
    updateHighScore();
    paused = true;
    mainMenu.showGameOverMenu(true);

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

void Game::restartGame() {
    //reset game objects
    cubeTower.reset();
    view.reset(sf::FloatRect(0, 0, 500.f, 500.f));
    movingCube.resetCubeForNewRound();
    scoreText.setString(std::to_string(score));

    //reset game properties
    score = 0;
    isGameOver = false;
    zoomAmount = 0;
    paused = false;

    mainMenu.showGameOverMenu(false);
}








/*std::cout << "Place Pos X " <<  placedPos.x << " Y " << placedPos.y << "\n";
std::cout << "Size X " <<  movingCube.getSizeX() << " Y " << movingCube.getSizeY() << "\n";
std::cout << "Size X " <<  newSize.x << " Y " << newSize.y << "\n";
//newSize.x = ceil(newSize.x);
//newSize.y = ceil(newSize.y);
//std::cout << "Size X " <<  newSize.x << " Y " << newSize.y << "\n";*/



/*rectangleShape.setPosition(cubeTower.topCube().getPosition().x,cubeTower.topCube().getPosition().y + 50);
            rectangleShape.setPoint(0, sf::Vector2f(cubeTower.topCube().getPoint(7).x, cubeTower.topCube().getPoint(7).y - 1));
            rectangleShape.setPoint(1, sf::Vector2f(cubeTower.topCube().getPoint(3).x + 1, cubeTower.topCube().getPoint(3).y));
            rectangleShape.setPoint(2, sf::Vector2f(cubeTower.topCube().getPoint(4).x, cubeTower.topCube().getPoint(4).y + 1));
            rectangleShape.setPoint(3, sf::Vector2f(cubeTower.topCube().getPoint(5).x - 1, cubeTower.topCube().getPoint(5).y));*/


/*rectangleShape.setPointCount(4);
    rectangleShape.setPoint(0,sf::Vector2f(50,0));
    rectangleShape.setPoint(1,sf::Vector2f(100,25));
    rectangleShape.setPoint(2,sf::Vector2f(50,50));
    rectangleShape.setPoint(3,sf::Vector2f(0,25));
    rectangleShape.setPosition(50,50);*/


