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
#include "vampire.hpp"
using std::cin;
using std::cout;
using std::endl;

//Generates Vampire attack value by rolling 1d12. Returns int value generated
//to be used in setAttack() function.
int Vampire::actionAttack()
{
    // srand(time(0));
    int atkValue = 0;
    atkValue = (rand() % 12) + 1;

    return atkValue;
}

//Generates Vampire defend value by rolling 1d6. Returns int value generated
//to be used in setDefense() function.
int Vampire::actionDefend()
{
    // srand(time(0));
    int defValue = 0;
    int charm = 0;

    //Roll of 1d6
    defValue = (rand() % 6) + 1;

    return defValue;
}

//Determines if a special attack should be used. This is determined based on the appropriate
//die rolls. Used in playRound() for each Attacker and Defender.
void Vampire::actionSpecialAttack()
{
}

//Determines if a special defend should be used. This is determined based on the appropriate
//die rolls. Used in playRound() for each Attacker and Defender.
//Generates charm ability if a 6 was rolled.
void Vampire::actionSpecialDefend()
{
    int charm = 0;
    if (getDefense() == 6)
    {
        charm = (rand() % 2) + 1;
        if (charm == 1)
        {
            for (int i = 0; i < 90; i++)
            {
                cout << '~';
            }
            cout << endl;
            cout << "However, the defending Vampire has charmed the attacker! The attacker will not strike." << endl;
            for (int i = 0; i < 90; i++)
            {
                cout << '~';
            }
            cout << endl;
            //Stops incoming damage for this round if opponent is charmed.
            setDefense(100);
        }
    }
}

//Determines if a special attack should be used. This is determined based on the appropriate
//die rolls. Used in playRound() for each Attacker and Defender.
void Vampire::actionSpecialOther()
{
}

//Restores a special ability for the next game if user plays again. Used in fantasy.cpp
void Vampire::restoreSpecial()
{
}
