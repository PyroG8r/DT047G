#include <iostream>
#include "Cube.h"


int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(500, 500), "Stacker");

    int x = 100;
    int y = 100;
    Cube cube(0, 0,x ,y);
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
                    cube.toggleDir();
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
            cube.setPosY(mouse.y);
            cube.setPosX(mouse.x);
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
        window.display();
    }

    return 0;
}