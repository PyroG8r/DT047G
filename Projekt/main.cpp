#include <SFML/Window.hpp>
#include <iostream>
#include "Cube.h"
#include "MovingCube.h"
#include "CubeTower.h"


int main()
{
    srand(time(0));
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(500, 500), "Stacker");
    sf::View view(sf::FloatRect(0, 0, 500.f, 500.f));

    //set the framerate limit to 60 frames per second
    window.setFramerateLimit(60);



    MovingCube movingCube(0, 0);

    CubeTower tower;
    tower.addCube(10,10);
    int counter = 0;

    while (window.isOpen())
    {
        sf::Event event;
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f mouseWorldPos = window.mapPixelToCoords(mousePos, view);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }

            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Space){
                    //move camera 1 cube height up
                    view.move(0,-50);
                    movingCube.placeCube();

                }
            }

        }


        counter++;
        if (!(counter % 2) ) {
            movingCube.move();
            counter = 0;
        }



        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
            movingCube.setPos(mouseWorldPos);
            tower.addCube(rand() % 20, rand() % 20);
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


        /*std::cout << movingCube.getSizeX() << "\n";
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            movingCube.toggleDir();
        }*/


        window.clear(sf::Color(200, 200, 200));

        window.setView(view);

        // print all cubes in tower using std::for_each
        std::for_each(tower.bottom(), tower.top(), [&window](Cube &cube){window.draw(cube.getShape());});
        window.draw(movingCube.getShape());

        window.display();
    }

    return 0;
}

