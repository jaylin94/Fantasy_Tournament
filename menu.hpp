#ifndef MENU_HPP
#define MENU_HPP
#include <string>
#include "game.hpp"

class Menu
{
private:
    int timesRun;
    char startChoice;
    std::string programName;

public:
    Menu()
    {
        timesRun = 0;
        startChoice = 's';
        programName = "Fantasy Tournament";
    }

    //Menu functions to display and check to start or quit
    void displayMenu();
    void displayLosers(Game *pGame);

    //Character count menu to determine number of characters
    void charCountMenu(Game *pGame);

    //Character type menu and choices
    void characterTypeMenu(Game *pGame, Vampire *vampire, Barbarian *barbarian, BlueMen *blueMen, Medusa *medusa, HarryPotter *harryPotter);
    int menuChoice(Game *pGame, int charCount, int charNum, Vampire *vampire, Barbarian *barbarian, BlueMen *blueMen, Medusa *medusa, HarryPotter *harryPotter);

    //Misc. display functions
    void displayLine();
    void displayContinue();

    //Menu functions to get choice and validate input
    bool startCheck();

    //Validates user start choice and integer input
    char validateStartChoice();
    int validateInt(int range);

    //Get functions for variables
    int getTimesRun()
    {
        return timesRun;
    }
    char getStartChoice()
    {
        return startChoice;
    }
    std::string getProgramName()
    {
        return programName;
    }

    //Set functions for variables
    void setTimesRun(int timesRun)
    {
        this->timesRun = timesRun;
    }
    void setStartChoice(char startChoice)
    {
        this->startChoice = startChoice;
    }
    void setProgramName(std::string programName)
    {
        this->programName = programName;
    }
};

#endif