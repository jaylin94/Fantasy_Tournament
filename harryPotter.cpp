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
#include <cstdlib>
#include <ctime>
#include "harryPotter.hpp"
using std::cin;
using std::cout;
using std::endl;

//Generates Harry Potter attack value by rolling 2d6. Returns int value generated
//to be used in setAttack() function.
int HarryPotter::actionAttack()
{
    int atkValue = 0;
    int roll1 = 0;
    int roll2 = 0;

    //2 rolls of d6
    roll1 = (rand() % 6) + 1;
    roll2 = (rand() % 6) + 1;

    //Sets attack value to two roll values
    atkValue = roll1 + roll2;

    return atkValue;
}

//Generates Harry Potter defense value by rolling 2d6. Returns int value generated
//to be used in setDefense() function. Also includes logic to see if Hogwarts can be cast
//and casts if possible, restoring strength to 20.
int HarryPotter::actionDefend()
{
    int defValue = 0;
    int roll1 = 0;
    int roll2 = 0;

    //2 rolls of d6
    roll1 = (rand() % 6) + 1;
    roll2 = (rand() % 6) + 1;

    defValue = roll1 + roll2;

    return defValue;
}

//Determines if a special other should be used. This is determined based on the appropriate
//die rolls. Used in playRound() for each Attacker and Defender. Brings Harry Potter back to
//life with a strength of 20.
void HarryPotter::actionSpecialOther()
{
    //If Hogwarts has not been cast, and if strength is <= 0, restores strength to 20
    if (getStrength() <= 0 && getHogwarts() == 0)
    {
        for (int i = 0; i < 90; i++)
        {
            cout << '~';
        }
        cout << endl;
        cout << "The defending Harry Potter was brought back from the brink of death by Dumbledore at Hogwarts!" << endl;
        cout << "Strength is restored to 20!" << endl;
        for (int i = 0; i < 90; i++)
        {
            cout << '~';
        }
        cout << endl;
        setStrength(20);
        setHogwarts(getHogwarts() + 1);
    }
}

//Restores a special ability for the next game if user plays again. Used in fantasy.cpp
//Resets Hogwarts so that it can be used again in a new game.
void HarryPotter::restoreSpecial()
{
    setHogwarts(0);
}

//Determines if a special attack should be used. This is determined based on the appropriate
//die rolls. Used in playRound() for each Attacker and Defender.
void HarryPotter::actionSpecialAttack()
{
}

//Determines if a special defend should be used. This is determined based on the appropriate
//die rolls. Used in playRound() for each Attacker and Defender.
void HarryPotter::actionSpecialDefend()
{
}