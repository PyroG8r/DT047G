#include <SFML/Graphics.hpp>


int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");

    sf::ConvexShape convex;
    convex.setPointCount(6);

    sf::Vector2i mouse = sf::Mouse::getPosition(window);

    convex.setPoint(0, sf::Vector2f(mouse.x + 50.f, mouse.y + 0.f));
    convex.setPoint(1, sf::Vector2f(mouse.x + 100.f, mouse.y + 25.f));
    convex.setPoint(2, sf::Vector2f(mouse.x + 100.f, mouse.y + 75.f));
    convex.setPoint(3, sf::Vector2f(mouse.x + 50.f, mouse.y + 100.f));
    convex.setPoint(4, sf::Vector2f(mouse.x + 0.f, mouse.y + 75.f));
    convex.setPoint(5, sf::Vector2f(mouse.x + 0.f, mouse.y + 25.f));


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        mouse = sf::Mouse::getPosition(window);

        convex.setPoint(0, sf::Vector2f(mouse.x + 50.f, mouse.y + 0.f));
        convex.setPoint(1, sf::Vector2f(mouse.x + 100.f, mouse.y + 25.f));
        convex.setPoint(2, sf::Vector2f(mouse.x + 100.f, mouse.y + 75.f));
        convex.setPoint(3, sf::Vector2f(mouse.x + 50.f, mouse.y + 100.f));
        convex.setPoint(4, sf::Vector2f(mouse.x + 0.f, mouse.y + 75.f));
        convex.setPoint(5, sf::Vector2f(mouse.x + 0.f, mouse.y + 25.f));

        window.clear();
        window.draw(convex);
        window.display();
    }

    return 0;
}