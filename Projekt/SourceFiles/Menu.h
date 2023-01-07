// "namn på uppgiften", DT047G
// Emil Jons 
// filnamn, 2022-12-28
// "kortfattat vad filen innehåller"


#ifndef PROJEKT_MENU_H
#define PROJEKT_MENU_H

#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_ITEMS_PAUSE_MENU 2
#define MAX_NUMBER_OF_ITEMS_GAME_OVER_MENU 2

class Menu {
public:
    Menu();

    /**
     * @brief Draws the pauseMenu to the window
     * @param window The window to draw to
    */
    void draw(sf::RenderWindow &window);

    /**
     * @brief Shows or hides the pauseMenu
     * @param show True or false depending on if the pauseMenu should be shown or not
    */
    void showPauseMenu(bool);

    void showGameOverMenu(bool);
    
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
    bool isRestartButtonPressed(sf::Vector2i mousePos);

    /**
     * @brief Updates the highscore
     * @param The new highscore
    */
    void updateHighScore(int);

private:
    void initializePauseMenu();
    void initializeGameOverMenu();
    /**
     * @brief Checks if the mouse is inside the button
     * @param mousePos The position of the mouse
     * @param button The button to check
     * @return True or false depending on if the mouse is inside the button
    */
    static bool isButtonPressed(sf::Vector2i mousePos, const sf::RectangleShape& button);

    sf::Font font;
    sf::Text pauseMenu[MAX_NUMBER_OF_ITEMS_PAUSE_MENU];
    sf::Text gameOverMenu[MAX_NUMBER_OF_ITEMS_GAME_OVER_MENU];
    sf::RectangleShape play_button;
    sf::RectangleShape exit_button;
    sf::RectangleShape restart_button;
    sf::Color buttonColor = sf::Color(208,106,107);
    int highScore = 0;
    bool isPauseMenuShown = true;
    bool isGameOverMenuShown = false;


};


#endif //PROJEKT_MENU_H
