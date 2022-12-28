// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-12-28
// "kortfattat vad filen innehåller"


#include <iostream>
#include <fstream>
#include "Menu.h"

Menu::Menu() {
    font.loadFromFile("Fonts/Roboto-Bold.ttf");
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::White);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(200, 150));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Exit");
    menu[1].setPosition(sf::Vector2f(200, 250));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color(64, 64, 64));
    menu[2].setCharacterSize(50);
    //open file highscore.txt and read highscore
    std::ifstream highscoreFile("highscore.txt");
    highscoreFile >> highscore;
    highscoreFile.close();
    menu[2].setString("HIGHSCORE: " + std::to_string(highscore));

    //center the text
    sf::FloatRect textRect = menu[2].getLocalBounds();
    menu[2].setOrigin(textRect.left + textRect.width / 2.0f,
                        textRect.top + textRect.height / 2.0f);

    menu[2].setPosition(sf::Vector2f(250, 50));

    background.setSize(sf::Vector2f(500, 500));
    background.setFillColor(sf::Color(0, 0, 0, 100));

    play_button.setSize(sf::Vector2f(100, 50));
    play_button.setFillColor(sf::Color(184, 184, 184));
    play_button.setPosition(sf::Vector2f(200, 150));

    exit_button.setSize(sf::Vector2f(100, 50));
    exit_button.setFillColor(sf::Color(184, 184, 184));
    exit_button.setPosition(sf::Vector2f(200, 250));



}

void Menu::draw(sf::RenderWindow &window) {
    if(show_menu) {
        window.draw(background);
        window.draw(play_button);
        window.draw(exit_button);
        for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
            window.draw(menu[i]);
        }
    }
    

}

void Menu::showMenu(bool input) {
    show_menu = input;

}

bool Menu::isPlayButtonPressed(sf::Vector2i mousePos) {
    if(mousePos.x > play_button.getPosition().x && mousePos.x < play_button.getPosition().x + play_button.getSize().x &&
       mousePos.y > play_button.getPosition().y && mousePos.y < play_button.getPosition().y + play_button.getSize().y) {
        return true;
    }
    return false;
}

bool Menu::isExitButtonPressed(sf::Vector2i mousePos) {
    if(mousePos.x > exit_button.getPosition().x && mousePos.x < exit_button.getPosition().x + exit_button.getSize().x &&
       mousePos.y > exit_button.getPosition().y && mousePos.y < exit_button.getPosition().y + exit_button.getSize().y) {
        return true;
    }
    return false;
}

