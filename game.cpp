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
#include <iomanip>
#include <string>
#include "game.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

//Plays a round of the main game. Takes a Game pointer and does not return
//anything. Uses the game pointer to output information, calculate attacker
//and defender damage/block values.
void Game::playRound(Game *pGame)
{
    int counter = 0;
    int damage = 0;
    int defended = 0;

    string attackerString;
    string defenderString;

    //Displays round number banner
    displayLine(2);
    cout << std::setw(40) << "ROUND " << getRoundNum() << "! FIGHT!" << endl;
    displayLine(2);
    // displayContinue();

    //Loops until both players have attacked, then round is ended
    while (counter < 2)
    {
        //Sets player who is attacking to player 1 or player 2
        if (counter == 0)
        {
            pGame->setPlayerNum(1);
        }
        else if (counter == 1)
        {
            pGame->setPlayerNum(2);
        }

        //Sets attacker and defender pointers and strings
        if (pGame->getPlayerNum() == 1)
        {
            pGame->setAttacker(pGame->getTeam1()->getHead());
            pGame->setDefender(pGame->getTeam2()->getHead());
            attackerString = "Player 1";
            defenderString = "Player 2";
        }
        else if (pGame->getPlayerNum() == 2)
        {
            pGame->setAttacker(pGame->getTeam2()->getHead());
            pGame->setDefender(pGame->getTeam1()->getHead());
            attackerString = "Player 2";
            defenderString = "Player 1";
        }

        //Displays who's attacking, who's defending, and defense points for defender
        cout << attackerString << "'s " << pGame->getAttacker()->getName() << " attacks!" << endl;
        cout << defenderString << "'s " << pGame->getDefender()->getName() << " defends." << endl;
        cout << defenderString << "'s armor: " << pGame->getDefender()->getArmor() << " points." << endl;
        cout << defenderString << "'s strength: " << pGame->getDefender()->getStrength() << " points." << endl;

        //Sets attack value to dice roll(s) in actionAttack for attacker
        pGame->getAttacker()->setAttack(pGame->getAttacker()->actionAttack());

        //Determines if attacker has a special to use
        pGame->getAttacker()->actionSpecialAttack();

        //Displays attack damage for attacker
        cout << attackerString << "'s " << pGame->getAttacker()->getName() << " attacks "
             << defenderString << "'s " << pGame->getDefender()->getName() << " for "
             << pGame->getAttacker()->getAttack() << " point(s) of damage (calculated from dice rolls)!" << endl;
        cout << endl;

        //Sets defense value to dice roll(s) in actionDefend for defender
        pGame->getDefender()->setDefense(pGame->getDefender()->actionDefend());

        //Checks for special ability of a character
        pGame->getDefender()->actionSpecialDefend();

        //Ensures that damage cannot be less than 0
        damage = pGame->getAttacker()->getAttack() - (pGame->getDefender()->getDefense() + pGame->getDefender()->getArmor());
        if (damage < 0)
        {
            damage = 0;
        }

        //Subtracts damage from defender's strength
        pGame->getDefender()->setStrength(pGame->getDefender()->getStrength() - damage);

        //Displays defense numbers for defender
        cout << defenderString << "'s " << pGame->getDefender()->getName() << " defends "
             << attackerString << "'s " << pGame->getAttacker()->getName() << " attack "
             << "stopping " << pGame->getDefender()->getDefense() << " point(s) of damage (calculated from dice rolls)!" << endl;
        cout << "Armor stops " << pGame->getDefender()->getArmor() << " point(s) of damage!" << endl;
        cout << endl;

        //Displays damage taken and new strength count after subtracting damage
        cout << defenderString << "'s " << pGame->getDefender()->getName() << " takes "
             << damage << " points of damage! " << endl;
        cout << defenderString << "'s " << pGame->getDefender()->getName() << " strength "
             << "is now " << pGame->getDefender()->getStrength() << "." << endl;
        cout << endl;

        //Checks for miscellaenous special abilities that are not attack or defend
        pGame->getDefender()->actionSpecialOther();

        //Displays message if a player's character is dead, game is over
        if (pGame->getDefender()->getStrength() <= 0)
        {
            cout << defenderString << "'s " << pGame->getDefender()->getName() << " is "
                 << "dead. " << attackerString << "'s " << pGame->getAttacker()->getName()
                 << " is victorious!" << endl;
            break;
        }

        counter++;
    }
    //Increments round number for round banner
    setRoundNum(getRoundNum() + 1);
}

//Displays line for visual formatting. Takes an integer argument to determine what the
//line will be made of. '1' for '*' line. '2' for 'z' line.
void Game::displayLine(int type)
{
    char line;
    if (type == 1)
    {
        line = '*';
    }
    else if (type == 2)
    {
        line = 'z';
    }

    for (int i = 0; i < 90; i++)
    {
        cout << line;
    }
    cout << endl;
}

//Asks user to press any key and/or ENTER/RETURN to continue.
void Game::displayContinue()
{
    std::string anyKey;
    cout << "Press any key and/or ENTER/RETURN to continue. " << endl;
    getline(cin, anyKey);
}
