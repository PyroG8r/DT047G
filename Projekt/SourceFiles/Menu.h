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

    /**
     * @brief Draws the menu to the window
     * @param window The window to draw to
    */
    void draw(sf::RenderWindow &window);

    /**
     * @brief Shows or hides the menu
     * @param show True or false depending on if the menu should be shown or not
    */
    void showMenu(bool);
    
    /**
     * @brief Checks if the play button is pressed
     * @param mousePos The position of the mouse
     * @return True or false depending on if the play button is pressed
    */
    bool isPlayButtonPressed(sf::Vector2i mousePos);

    /**
     * @brief Checks if the exit button is pressed
     * @param mousePos The position of the mouse
     * @return True or false depending on if the exit button is pressed
    */
    bool isExitButtonPressed(sf::Vector2i mousePos);

    /**
     * @brief Updates the highscore
     * @param The new highscore
    */
    void updateHighScore(int);

private:
    /**
     * @brief Checks if the mouse is inside the button
     * @param mousePos The position of the mouse
     * @param button The button to check
     * @return True or false depending on if the mouse is inside the button
    */
    static bool isButtonPressed(sf::Vector2i mousePos, const sf::RectangleShape& button);

    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
    sf::RectangleShape background;
    sf::RectangleShape play_button;
    sf::RectangleShape exit_button;
    sf::Color buttonColor = sf::Color(208,106,107);
    int highScore = 0;
    bool show_menu = true;


};


#endif //PROJEKT_MENU_H
