#include <iostream>
#include "Cube.h"
#include "MovingCube.h"
#include "CubeTower.h"


int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(500, 500), "Stacker");

    int x = 100;
    int y = 100;
    MovingCube cube(x, y, 1, 1);
    CubeTower cube1;
    int counter = 0;

    sf::Vector2i mouse;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    //cube.toggleDir();
                }
            }

        }


        /*counter++;
        if (!(counter % 2) ) {
            cube.move();
            counter = 0;
        }
*/
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
            mouse = sf::Mouse::getPosition(window);
            cube.setPos(sf::Vector2f(mouse.x, mouse.y));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            cube.increaseLeft();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            cube.decreaseLeft();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            cube.increaseRight();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            cube.decreaseRight();
        }

        /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            cube.toggleDir();
        }*/


        window.clear();
        window.draw(cube.getCube());
        window.draw(cube1.getCube());
        window.display();
    }

    return 0;
}