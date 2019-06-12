#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "queue.hpp"
#include "character.hpp"
#include "menu.hpp"
#include "game.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    srand(time(0));

    Game game1;
    Game *pGame = &game1;
    Menu menu1;

    Queue team1;
    Queue *pTeam1 = &team1;
    Queue team2;
    Queue *pTeam2 = &team2;
    Queue losers;
    Queue *pLosers = &losers;

    menu1.displayMenu();
    menu1.validateStartChoice();

    while (menu1.startCheck())
    {

        //Select character for player 1
        pGame->setPlayerNum(1);
        menu1.characterTypeMenu(pGame);
        menu1.menuChoice(pGame);
        pGame->getPlayer1()->setStrength(pGame->getPlayer1()->getRestoreStrength());

        //Select character for player 2
        pGame->setPlayerNum(2);
        menu1.characterTypeMenu(pGame);
        menu1.menuChoice(pGame);
        pGame->getPlayer2()->setStrength(pGame->getPlayer2()->getRestoreStrength());

        while (pGame->getPlayer1()->getStrength() > 0 && pGame->getPlayer2()->getStrength() > 0)
        {
            //Display and run player 1 attacking player 2
            pGame->setPlayerNum(1);
            pGame->playRound(pGame);
        }

        //Display menu to continue running
        menu1.displayMenu();
        menu1.validateStartChoice();
    }

    return 0;
}