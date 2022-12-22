// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-12-21
// "kortfattat vad filen innehåller"


#include "Game.h"

Game::Game(const int width, const int height, const std::string& gameTitle)
: window(sf::VideoMode(500, 500), gameTitle),
  movingCube(0, 0),
  view(sf::FloatRect(0, 0, 500.f, 500.f))
{
    window.setFramerateLimit(60);
    settings.antialiasingLevel = 8;


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
    window.setView(view);

}

void Game::handleInputs() {


    //main event loop
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space) {
                placeCube();
            }
        }
    }
}


void Game::updateObjects() {

    movingCube.move();

    mousePos = sf::Mouse::getPosition(window);
    mouseWorldPos = window.mapPixelToCoords(mousePos, view);


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

    window.clear(sf::Color(200, 200, 200));

    // print all cubes in tower using std::for_each
    std::for_each(cubeTower.bottom(), cubeTower.top(), [this](Cube &cube){window.draw(cube.getShape());});
    window.draw(movingCube.getShape());

    window.display();

}

void Game::placeCube() {
    //move camera 1 cube height up
    view.move(0,-50);
    window.setView(view);

    double overHang;
    FixedCube topCube = cubeTower.topCube();
    sf::Vector2f placedPos(movingCube.getPos());
    sf::Vector2f newSize(movingCube.getSizeX(),movingCube.getSizeY());


    overHang = movingCube.placeCube(topCube);

    //moving along x placed "under" tower
    if (placedPos.x < topCube.getPos().x && !movingCube.getMovingPath()){
        newSize.x = movingCube.getSizeX() - overHang;
        placedPos = topCube.getPos();
    }
    //moving along x placed "above" tower
    if (placedPos.x > topCube.getPos().x && !movingCube.getMovingPath()){
        newSize.x = movingCube.getSizeX() - overHang;
        placedPos.y += 50;
    }
    //moving along y placed "above" tower
    if (placedPos.x < topCube.getPos().x && movingCube.getMovingPath()){
        newSize.y = movingCube.getSizeY() - overHang;
        placedPos.y += 100;
    }
    //moving along y placed "under" tower
    if (placedPos.x > topCube.getPos().x && movingCube.getMovingPath()){
        newSize.y = movingCube.getSizeY() - overHang;
        placedPos = topCube.getPos();
    }



    cubeTower.addCube(newSize, placedPos);
    movingCube.setSize(sf::Vector2f(newSize.x,newSize.y));

}

