/*********************************************************************
** Program name: Fantasy Tournament
** Author: Jay Lin
** Date: 05/24/2019
** Description: This program allows one user to pick two teams that
** will have a simulated fight. Fights will be determined by the individual
** character statistics. The users can choose from: Vampire, Barbarian, 
** Blue Men, Medusa, Harry Potter as their character. Each team will fight until
** one team has no fighters reamining.
** To start, extract all files. Type "make" to compile the program.
** Then type "./fantasy" to run the program.
*********************************************************************/
#include <iostream>
#include <string>
#include "menu.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

//Displays menu for the game, prompts user to start or quit. Provides a
//quick description of the game. Displays menu to rerun as well.
void Menu::displayMenu()
{
    //Times run checks if this is the first time running.
    //The welcome message will only be displayed if timesRun is 0.
    if (timesRun == 0)
    {
        //gameName is set by getProgramName() in the constructor.
        cout << "Welcome to " << getProgramName() << "." << endl;

        cout << "This is a game where two legendary teams battle." << endl;

        cout << "Please enter 's' to start, or 'q' to quit. " << endl;
    }
    //Displays rerun prompt if timesRun is > 0.
    else if (timesRun > 0)
    {
        cout << "Continue with " << getProgramName() << "? "
             << "Enter 's' to start, 'q' to quit." << endl;
    }
    setTimesRun(getTimesRun() + 1);
}

//Displays all losers of the loser container (defeated characters) in reverse order. Prompts user to display or continue.
//Takes a Game pointer.
void Menu::displayLosers(Game *pGame)
{
    cout << "Would you like to see the defeated characters? Please enter '1' for yes, '2' for no." << endl;
    int userChoice = validateInt(3);

    switch (userChoice)
    {
    case 1:
        pGame->getLosers()->revPrintQueue();
        break;
    case 2:
        return;
    }
}

//Displays the second menu, the character selection menu for player 1 and player 2.
//Players will have 5 options:
//1. Vampire
//2. Barbarian
//3. Blue Men
//4. Medusa
//5. Harry Potter
//Takes a Game pointer to set display the correct character prompts. PlayerNum in Game must be set
//before this function is called in order to display the correct player selecting a character.
//Requires derived character pointers: vampire, barbarian, blueMen, medusa, harryPotter to display information
void Menu::characterTypeMenu(Game *pGame, Vampire *vampire, Barbarian *barbarian, BlueMen *blueMen, Medusa *medusa, HarryPotter *harryPotter)
{
    //Determines menu to display for Player 1 or Player 2
    string playerString;
    if (pGame->getPlayerNum() == 1)
    {
        playerString = "Player 1";
    }
    else if (pGame->getPlayerNum() == 2)
    {
        playerString = "Player 2";
    }

    //Displays prompts for characters to choose from including
    //Character Descriptions and Special Descriptions
    cout << endl;
    cout << "Choose for " << playerString << "." << endl;
    cout << "Which character would you like to choose? " << endl;
    for (int i = 0; i < 45; i++)
    {
        cout << '=';
    }
    cout << endl;

    cout << "Enter '1' for Vampire. " << endl;
    cout << "Charactersitics: " << vampire->getCharDescrip() << endl;
    cout << "Special Abilities: " << vampire->getSpecialDescrip() << endl;
    cout << endl;

    cout << "Enter '2' for Barbarian. " << endl;
    cout << "Charactersitics: " << barbarian->getCharDescrip() << endl;
    cout << "Special Abilities: " << barbarian->getSpecialDescrip() << endl;
    cout << endl;

    cout << "Enter '3' for Blue Men. " << endl;
    cout << "Charactersitics: " << blueMen->getCharDescrip() << endl;
    cout << "Special Abilities: " << blueMen->getSpecialDescrip() << endl;
    cout << endl;

    cout << "Enter '4' for Medusa. " << endl;
    cout << "Charactersitics: " << medusa->getCharDescrip() << endl;
    cout << "Special Abilities: " << medusa->getSpecialDescrip() << endl;
    cout << endl;

    cout << "Enter '5' for Harry Potter. " << endl;
    cout << "Charactersitics: " << harryPotter->getCharDescrip() << endl;
    cout << "Special Abilities: " << harryPotter->getSpecialDescrip() << endl;
    cout << endl;
}

//Displays menu and sets character count for desired number of characters. Takes a Game pointer.
//Integer validation with validateInt().
void Menu::charCountMenu(Game *pGame)
{
    cout << "How many fighters do you want each team to have? " << endl;
    int userInt = validateInt(2);
    pGame->setCharCount(userInt);
    pGame->setCharNum(userInt);
}

//Gets the user choice for the second menu, the character selection menu for player 1 and player 2.
//Players will have 5 options:
//1. Vampire
//2. Barbarian
//3. Blue Men
//4. Medusa
//5. Harry Potter
//Takes a Game pointer to set each player's character. PlayerNum in Game must be set
//before this function is called in order to select a character for the correct player.
//Requires derived character pointers: vampire, barbarian, blueMen, medusa, harryPotter to display information
//Also takes character count, character number to pass into team queues/containers
int Menu::menuChoice(Game *pGame, int charCount, int charNum, Vampire *vampire, Barbarian *barbarian, BlueMen *blueMen, Medusa *medusa, HarryPotter *harryPotter)
{
    string playerString;
    string characterName;
    string namePrompt = "Please enter a name for this character: ";
    //Gets and validates user integer input for menu options 1-6.
    int userChoice = validateInt(2);

    if (pGame->getPlayerNum() == 1)
    {
        playerString = "Player 1";

        //Menu options for user, gets required user input, runs functions.
        //Team1, adds new character to the back, prompts for name, displays character type and name, decrements character number.
        switch (userChoice)
        {
        case 1:
            //Sets player1 pointer in Game to first Vampire object in Game
            pGame->getTeam1()->addBack(userChoice, charCount, charNum, vampire, barbarian, blueMen, medusa, harryPotter);
            cout << namePrompt << endl;
            getline(cin, characterName);
            pGame->getTeam1()->getEnd()->setName(characterName);
            displayLine();
            cout << playerString << " has selected " << vampire->getCharacterType() << "!" << endl;
            cout << playerString << " has named it: " << pGame->getTeam1()->getEnd()->getName() << endl;
            displayLine();
            pGame->setCharNum(pGame->getCharNum() - 1);
            break;

        case 2:
            //Sets player1 pointer in Game to first Barbarian object in Game
            pGame->getTeam1()->addBack(userChoice, charCount, charNum, vampire, barbarian, blueMen, medusa, harryPotter);
            cout << namePrompt << endl;
            getline(cin, characterName);
            pGame->getTeam1()->getEnd()->setName(characterName);
            displayLine();
            cout << playerString << " has selected " << barbarian->getCharacterType() << "!" << endl;
            cout << playerString << " has named it: " << pGame->getTeam1()->getEnd()->getName() << endl;
            displayLine();
            pGame->setCharNum(pGame->getCharNum() - 1);
            break;

        case 3:
            //Sets player1 pointer in Game to first Blue Men object in Game
            pGame->getTeam1()->addBack(userChoice, charCount, charNum, vampire, barbarian, blueMen, medusa, harryPotter);
            cout << namePrompt << endl;
            getline(cin, characterName);
            pGame->getTeam1()->getEnd()->setName(characterName);
            displayLine();
            cout << playerString << " has selected " << blueMen->getCharacterType() << "!" << endl;
            cout << playerString << " has named it: " << pGame->getTeam1()->getEnd()->getName() << endl;
            displayLine();
            pGame->setCharNum(pGame->getCharNum() - 1);
            break;

        case 4:
            //Sets player1 pointer in Game to first Medusa object in Game
            pGame->getTeam1()->addBack(userChoice, charCount, charNum, vampire, barbarian, blueMen, medusa, harryPotter);
            cout << namePrompt << endl;
            getline(cin, characterName);
            pGame->getTeam1()->getEnd()->setName(characterName);
            displayLine();
            cout << playerString << " has selected " << medusa->getCharacterType() << "!" << endl;
            cout << playerString << " has named it: " << pGame->getTeam1()->getEnd()->getName() << endl;
            displayLine();
            pGame->setCharNum(pGame->getCharNum() - 1);
            break;

        case 5:
            //Sets player1 pointer in Game to first Harry Potter object in Game
            pGame->getTeam1()->addBack(userChoice, charCount, charNum, vampire, barbarian, blueMen, medusa, harryPotter);
            cout << namePrompt << endl;
            getline(cin, characterName);
            pGame->getTeam1()->getEnd()->setName(characterName);
            displayLine();
            cout << playerString << " has selected " << harryPotter->getCharacterType() << "!" << endl;
            cout << playerString << " has named it: " << pGame->getTeam1()->getEnd()->getName() << endl;
            displayLine();
            pGame->setCharNum(pGame->getCharNum() - 1);
            break;
        }
    }
    //Team 2, adds new character to the back, prompts for name, displays character type and name, decrements character number.
    else
    {
        playerString = "Player 2";

        //Menu options for user, gets required user input, runs functions.
        switch (userChoice)
        {
        case 1:
            //Sets player2 pointer in Game to the second Vampire object in Game
            pGame->getTeam2()->addBack(userChoice, charCount, charNum, vampire, barbarian, blueMen, medusa, harryPotter);
            cout << namePrompt << endl;
            getline(cin, characterName);
            pGame->getTeam2()->getEnd()->setName(characterName);
            displayLine();
            cout << playerString << " has selected " << vampire->getCharacterType() << "!" << endl;
            cout << playerString << " has named it: " << pGame->getTeam2()->getEnd()->getName() << endl;
            displayLine();
            pGame->setCharNum(pGame->getCharNum() - 1);
            break;

        case 2:
            //Sets player2 pointer in Game to the second Barbarian object in Game
            pGame->getTeam2()->addBack(userChoice, charCount, charNum, vampire, barbarian, blueMen, medusa, harryPotter);
            cout << namePrompt << endl;
            getline(cin, characterName);
            pGame->getTeam2()->getEnd()->setName(characterName);
            displayLine();
            cout << playerString << " has selected " << barbarian->getCharacterType() << "!" << endl;
            cout << playerString << " has named it: " << pGame->getTeam2()->getEnd()->getName() << endl;
            displayLine();
            pGame->setCharNum(pGame->getCharNum() - 1);
            break;

        case 3:
            //Sets player2 pointer in Game to the second Blue Men object in Game
            pGame->getTeam2()->addBack(userChoice, charCount, charNum, vampire, barbarian, blueMen, medusa, harryPotter);
            cout << namePrompt << endl;
            getline(cin, characterName);
            pGame->getTeam2()->getEnd()->setName(characterName);
            displayLine();
            cout << playerString << " has selected " << blueMen->getCharacterType() << "!" << endl;
            cout << playerString << " has named it: " << pGame->getTeam2()->getEnd()->getName() << endl;
            displayLine();
            pGame->setCharNum(pGame->getCharNum() - 1);
            break;

        case 4:
            //Sets player2 pointer in Game to the second Medusa object in Game
            pGame->getTeam2()->addBack(userChoice, charCount, charNum, vampire, barbarian, blueMen, medusa, harryPotter);
            cout << namePrompt << endl;
            getline(cin, characterName);
            pGame->getTeam2()->getEnd()->setName(characterName);
            displayLine();
            cout << playerString << " has selected " << medusa->getCharacterType() << "!" << endl;
            cout << playerString << " has named it: " << pGame->getTeam2()->getEnd()->getName() << endl;
            displayLine();
            pGame->setCharNum(pGame->getCharNum() - 1);
            break;

        case 5:
            //Sets player2 pointer in Game to the second Harry Potter object in Game
            pGame->getTeam2()->addBack(userChoice, charCount, charNum, vampire, barbarian, blueMen, medusa, harryPotter);
            cout << namePrompt << endl;
            getline(cin, characterName);
            pGame->getTeam2()->getEnd()->setName(characterName);
            displayLine();
            cout << playerString << " has selected " << harryPotter->getCharacterType() << "!" << endl;
            cout << playerString << " has named it: " << pGame->getTeam2()->getEnd()->getName() << endl;
            displayLine();
            pGame->setCharNum(pGame->getCharNum() - 1);
            break;
        }
    }
    return 0;
}

//Validates user integer input for a variety of functinos in Menu. Takes an integer parameter to
//determine the range of acceptable inputs from the user. Returns an integer as a choice for
//corresponding menu functions.
int Menu::validateInt(int range)
{
    //Float validation adapted from: https://www.quora.com/How-do-I-check-if-a-number-is-float-on-C++
    double choice = 0.0;
    int floatTest = 0;

    int upperLim = 0;
    int lowerLim = 0;
    string message;

    //Range for main menu choice, 1 - 5
    if (range == 1)
    {
        message = "Please enter a valid integer 1, 2, 3, 4, or 5.";
        upperLim = 5;
        lowerLim = 1;
    }
    //Range for steps, rows and columns, 1 - 32767
    else if (range == 2)
    {
        message = "Please enter a valid integer > 1, < 32767. ";
        upperLim = 32767;
        lowerLim = 1;
    }
    else if (range == 3)
    {
        message = "Please enter a valid integer 1 or 2. ";
        upperLim = 2;
        lowerLim = 1;
    }

    while (true)
    {
        //Detects invalid string/char input and reprompts user
        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << message << endl;
        }
        //Detects float input, out of range input
        floatTest = choice * 100000000.0;
        if (((floatTest % 100000000) > 0) || choice < lowerLim || choice > upperLim)
        {
            //Clears extraction failure flag
            cin.clear();
            //Ignores next 10000 inputs in the buffer until \n
            cin.ignore(10000, '\n');
            cout << message << endl;
        }
        //Valid input, returns integer
        else
        {
            cin.ignore(10000, '\n');
            return choice;
        }
    }
}

//Validates menu input choice to start the program or quit.
//Ensures that input is a character of 's' to start or
//'q' to quit. Returns a character of 's' or 'q'.
char Menu::validateStartChoice()
{
    string choice;
    while (true)
    {
        cin >> (choice);
        //Character array to validate user input for a character, other inputs are
        //invalid.
        char newChoice[1];
        newChoice[0] = choice[0];
        cin.ignore(10000, '\n');
        if (choice.length() > 1)
        {
            cout << "Please enter 's' to start or 'q' to quit." << endl;
        }
        else if (newChoice[0] == 's' || newChoice[0] == 'q')
        {
            setStartChoice(newChoice[0]);
            return newChoice[0];
        }
        else
        {
            cout << "Please enter 's' to start or 'q' to quit." << endl;
        }
    }
}

//Prompts user for menu input to start or quit, using
//getMenuChoice(). Quits if user input is 'q'. Returns a bool of true (s) or false (q).
bool Menu::startCheck()
{
    if (getStartChoice() == 'q')
    {
        return false;
    }
    else
    {
        return true;
    }
}

//Displays a line of '~' characters, 90 characters long.
void Menu::displayLine()
{
    for (int i = 0; i < 90; i++)
    {
        cout << '~';
    }
    cout << endl;
}

//Asks user to press any key and/or ENTER/RETURN to continue.
void Menu::displayContinue()
{
    std::string anyKey;
    cout << "Press any key and/or ENTER/RETURN to continue. " << endl;
    getline(cin, anyKey);
}
