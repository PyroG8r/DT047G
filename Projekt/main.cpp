#include <iostream>
#include "Cube.h"
#include "MovingCube.h"
#include "CubeTower.h"


int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(500, 500), "Stacker");
    //set the framerate limit to 60 frames per second
    window.setFramerateLimit(60);
    

    int x = 100;
    int y = 100;
    MovingCube movingCube(x, y, 1, 1);

    CubeTower tower;
    tower.addCube(10,10);
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
                    movingCube.toggleDir();
                }
            }

        }


        counter++;
        if (!(counter % 2) ) {
            movingCube.move();
            counter = 0;
        }



        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
            mouse = sf::Mouse::getPosition(window);
            movingCube.setPos(sf::Vector2f(mouse.x, mouse.y));
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

/*
        std::cout << movingCube.getSizeX() << "\n";
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            movingCube.toggleDir();
        }
*/

        window.clear(sf::Color(200, 200, 200));
        // print all cubes in tower using std::for_each
        std::for_each(tower.bottom(), tower.top(), [&window](Cube &cube){window.draw(cube.getShape());});
        window.draw(movingCube.getShape());

        window.display();
    }

    return 0;
}

