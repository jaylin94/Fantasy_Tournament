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
#include "barbarian.hpp"
using std::cin;
using std::cout;
using std::endl;

//Generates Barbarian attack value by rolling 2d6. Returns int value generated
//to be used in setAttack() function.
int Barbarian::actionAttack()
{
    int atkValue = 0;
    int roll1 = 0;
    int roll2 = 0;

    //2 rolls of d6
    roll1 = (rand() % 6) + 1;
    roll2 = (rand() % 6) + 1;

    atkValue = roll1 + roll2;

    return atkValue;
}

//Generates Barbarian defend value by rolling 2d6. Returns int value generated
//to be used in setDefense() function.
int Barbarian::actionDefend()
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

//Determines if a special attack should be used. This is determined based on the appropriate
//die rolls. Used in playRound() for each Attacker and Defender.
void Barbarian::actionSpecialAttack()
{
}

//Determines if a special defend should be used. This is determined based on the appropriate
//die rolls. Used in playRound() for each Attacker and Defender.
void Barbarian::actionSpecialDefend()
{
}

//Determines if a special other should be used. This is determined based on the appropriate
//die rolls. Used in playRound() for each Attacker and Defender.
void Barbarian::actionSpecialOther()
{
}
//Restores a special ability for the next game if user plays again. Used in fantasy.cpp
void Barbarian::restoreSpecial()
{
}