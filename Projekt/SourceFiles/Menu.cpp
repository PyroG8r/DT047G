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
    //open file highScore.txt and read highScore
    std::ifstream highscoreFile("highScore.txt");
    highscoreFile >> highScore;
    highscoreFile.close();
    menu[2].setString("HIGHSCORE: " + std::to_string(highScore));

    //center the text
    sf::FloatRect textRect = menu[2].getLocalBounds();
    menu[2].setOrigin(textRect.left + textRect.width / 2.0f,
                        textRect.top + textRect.height / 2.0f);

    menu[2].setPosition(sf::Vector2f(250, 50));

    background.setSize(sf::Vector2f(500, 500));
    background.setFillColor(sf::Color(226,191,145));

    play_button.setSize(sf::Vector2f(100, 50));
    play_button.setFillColor(buttonColor);
    play_button.setPosition(sf::Vector2f(200, 150));

    exit_button.setSize(sf::Vector2f(100, 50));
    exit_button.setFillColor(buttonColor);
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
    if(show_menu){
        return isButtonPressed(mousePos, play_button);
    }
    return false;
}

bool Menu::isExitButtonPressed(sf::Vector2i mousePos) {
    if(show_menu){
        return isButtonPressed(mousePos, exit_button);
    }
    return false;
}

bool Menu::isButtonPressed(sf::Vector2i mousePos, const sf::RectangleShape& button) {
    if(mousePos.x > (int)button.getPosition().x && mousePos.x < (int)button.getPosition().x + (int)button.getSize().x &&
       mousePos.y > (int)button.getPosition().y && mousePos.y < (int)button.getPosition().y + (int)button.getSize().y) {
        return true;
    }
    return false;
}

void Menu::updateHighScore(int newHighScore) {
    highScore = newHighScore;
    menu[2].setString("HIGHSCORE: " + std::to_string(highScore));
}


