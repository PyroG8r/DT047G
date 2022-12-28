// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-12-28
// "kortfattat vad filen innehåller"


#ifndef PROJEKT_MENU_H
#define PROJEKT_MENU_H

#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_ITEMS 3

class Menu {
public:
    Menu();
    void draw(sf::RenderWindow &window);
    void showMenu(bool);
    
    //detect mouse position and check if it is inside the play button
    bool isPlayButtonPressed(sf::Vector2i mousePos);
    bool isExitButtonPressed(sf::Vector2i mousePos);


private:
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
    sf::RectangleShape background;
    sf::RectangleShape play_button;
    sf::RectangleShape exit_button;
    int highscore = 0;
    bool show_menu = true;


};


#endif //PROJEKT_MENU_H
