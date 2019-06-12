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
#include <cstdlib>
#include <ctime>
#include "character.hpp"
#include "vampire.hpp"
#include "menu.hpp"
#include "game.hpp"
#include "queue.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

//Functions to run main tournament, reset scores, deallocate character objects
void tournament(Game *pGame);
void resetScores(Game *pGame);
void deallocCharacters(Vampire *vampire, Barbarian *barbarian, BlueMen *blueMen, Medusa *medusa, HarryPotter *harryPotter);

int main()
{
    //Seeds rand() for dice rolls in character attack/defend actions
    srand(time(0));

    //Game object and pointer to pass into functions
    Game game1;
    Game *pGame = &game1;

    //Menu object to call main menu functions
    Menu menu1;

    //Queue objects for the 3 containers, team 1, team 2, and losers
    Queue team1;
    Queue team2;
    Queue losers;

    //Character type pointers to pass in menu and queue functions for team 1 and team 2
    Vampire *vampire;
    Vampire *vampire2;
    Barbarian *barbarian;
    Barbarian *barbarian2;
    BlueMen *blueMen;
    BlueMen *blueMen2;
    Medusa *medusa;
    Medusa *medusa2;
    HarryPotter *harryPotter;
    HarryPotter *harryPotter2;

    //Sets container pointers in game1 object to queue objects in main
    pGame->setTeam1(&team1);
    pGame->setTeam2(&team2);
    pGame->setLosers(&losers);

    //Displays menu and validates start choice
    menu1.displayMenu();
    menu1.validateStartChoice();

    //Re-runs program while user does not exit or quit
    while (menu1.startCheck())
    {
        //Runs character count menu for user and allocates memory for derived character objects
        menu1.charCountMenu(pGame);
        vampire = new Vampire[pGame->getCharCount()];
        barbarian = new Barbarian[pGame->getCharCount()];
        blueMen = new BlueMen[pGame->getCharCount()];
        medusa = new Medusa[pGame->getCharCount()];
        harryPotter = new HarryPotter[pGame->getCharCount()];

        vampire2 = new Vampire[pGame->getCharCount()];
        barbarian2 = new Barbarian[pGame->getCharCount()];
        blueMen2 = new BlueMen[pGame->getCharCount()];
        medusa2 = new Medusa[pGame->getCharCount()];
        harryPotter2 = new HarryPotter[pGame->getCharCount()];

        //Select character for player 1
        pGame->setPlayerNum(1);

        //Allows user to select character, runs selection for number of characters
        for (int i = 0; i < (pGame->getCharCount()); i++)
        {
            menu1.characterTypeMenu(pGame, vampire, barbarian, blueMen, medusa, harryPotter);
            menu1.menuChoice(pGame, pGame->getCharCount(), pGame->getCharNum(), vampire, barbarian, blueMen, medusa, harryPotter);
        }
        //Displays selected team of characters by name
        pGame->getTeam1()->printQueue();

        //Sets character number to set as the character array index in addBack()
        pGame->setCharNum(pGame->getCharCount());

        //Select character for player 2
        pGame->setPlayerNum(2);

        //Allows user to select character, if user exits with 6, menuChoice returns 1 and breaks from the loop
        for (int i = 0; i < (pGame->getCharCount()); i++)
        {
            menu1.characterTypeMenu(pGame, vampire2, barbarian2, blueMen2, medusa2, harryPotter2);
            menu1.menuChoice(pGame, pGame->getCharCount(), pGame->getCharNum(), vampire2, barbarian2, blueMen2, medusa2, harryPotter2);
        }
        //Displays selected team of characters by name
        pGame->getTeam2()->printQueue();

        //Runs tournament, attackers/defenders, team rotations
        tournament(pGame);

        //If a team is out of characters that are alive, declare winning team
        if (pGame->getTeam1()->getHead() == nullptr)
        {
            cout << "The Winner is Team 2!" << endl;
            cout << "Team 2's score: " << pGame->getTeam2()->getScore() << endl;
        }
        else if (pGame->getTeam2()->getHead() == nullptr)
        {
            cout << "The Winner is Team 1!" << endl;
            cout << "Team 1's score: " << pGame->getTeam1()->getScore() << endl;
        }

        //Reset team scores for the next tournament
        resetScores(pGame);

        //Displays loser container if user chooses to view (displays last character defeated to first character defeated)
        menu1.displayLosers(pGame);

        //Display menu to continue running
        menu1.displayMenu();

        //If user re-runs tournament with new characters, set each container to point to null, delete losers, deallocate character arrays
        if (menu1.validateStartChoice() == 's')
        {
            pGame->getTeam1()->dealloc();
            pGame->getTeam2()->dealloc();
            pGame->getLosers()->loserDelete();
            pGame->getLosers()->dealloc();
            deallocCharacters(vampire, barbarian, blueMen, medusa, harryPotter);
            deallocCharacters(vampire2, barbarian2, blueMen2, medusa2, harryPotter2);
        }
    }

    //Deletes dynamically allocated character arrays if program has completed a tournament, else do not delete and return 0;
    if (menu1.getTimesRun() > 1)
    {
        pGame->getLosers()->loserDelete();
        deallocCharacters(vampire, barbarian, blueMen, medusa, harryPotter);
        deallocCharacters(vampire2, barbarian2, blueMen2, medusa2, harryPotter2);
    }

    return 0;
}

//Tournament function that runs the main tournament for each team of characters. Takes a Game pointer as a parameter
//to call queue functions. Does not return a value. Plays round, adds defeated characters to loser container, removes
//defeated character from team, calculates scores, rotates each team of characters.
void tournament(Game *pGame)
{
    while (pGame->getTeam1()->getHead() != nullptr && pGame->getTeam2()->getHead() != nullptr)
    {
        //Plays round, team 1 attacks first
        pGame->setPlayerNum(1);
        pGame->playRound(pGame);

        //Determines if a character is defeated, if so, add to loser container, remove from team. Restores partial strength
        //of winning character, adds scores to teams.
        if (pGame->getTeam1()->getHead()->getStrength() <= 0)
        {
            pGame->getLosers()->addBackLoser(pGame->getTeam1()->getHead());
            pGame->getTeam1()->removeFront();
            pGame->getTeam2()->setScore(pGame->getTeam2()->getScore() + 1);
            pGame->getTeam2()->getHead()->restorePartialStr();
            cout << "Team 1's score: " << pGame->getTeam1()->getScore() << endl;
            cout << "Team 2's score: " << pGame->getTeam2()->getScore() << endl;

            //Rotates characters for each team if count is > 1 and a team still has undefeated characters
            if (pGame->getCharCount() > 1 && pGame->getTeam1()->getHead() != nullptr && pGame->getTeam2()->getHead() != nullptr)
            {
                pGame->getTeam1()->rotate();
                pGame->getTeam2()->rotate();
            }
        }
        //Determines if a character is defeated, if so, add to loser container, remove from team. Restores partial strength
        //of winning character, adds scores to teams.
        else if (pGame->getTeam2()->getHead()->getStrength() <= 0)
        {
            pGame->getLosers()->addBackLoser(pGame->getTeam2()->getHead());
            pGame->getTeam2()->removeFront();
            pGame->getTeam1()->setScore(pGame->getTeam1()->getScore() + 1);
            pGame->getTeam1()->getHead()->restorePartialStr();
            cout << "Team 1's score: " << pGame->getTeam1()->getScore() << endl;
            cout << "Team 2's score: " << pGame->getTeam2()->getScore() << endl;

            //Rotates characters for each team if count is > 1 and a team still has undefeated characters
            if (pGame->getCharCount() > 1 && pGame->getTeam2()->getHead() != nullptr && pGame->getTeam1()->getHead() != nullptr)
            {
                pGame->getTeam2()->rotate();
                pGame->getTeam1()->rotate();
            }
        }
    }
}

//Resets team scores to 0 for each tournament. Takes a Game pointer as a parameter.
void resetScores(Game *pGame)
{
    pGame->getTeam1()->setScore(0);
    pGame->getTeam2()->setScore(0);
}

//Deallocates derived character arrays that are dynamically allocated in the
//Game class constructor. Deletes vampire, barbarian, bluemen, medusa, harry
//potter arrays.
void deallocCharacters(Vampire *vampire, Barbarian *barbarian, BlueMen *blueMen, Medusa *medusa, HarryPotter *harryPotter)
{
    delete[] vampire;
    delete[] barbarian;
    delete[] blueMen;
    delete[] medusa;
    delete[] harryPotter;
}