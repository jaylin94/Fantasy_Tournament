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
#include "bluemen.hpp"
using std::cin;
using std::cout;
using std::endl;

//Generates Blue Men attack value by rolling 2d10. Returns int value generated
//to be used in setAttack() function.
int BlueMen::actionAttack()
{
    int atkValue = 0;
    int roll1 = 0;
    int roll2 = 0;

    //2 rolls of d6
    roll1 = (rand() % 10) + 1;
    roll2 = (rand() % 10) + 1;

    atkValue = roll1 + roll2;

    return atkValue;
}

//Generates Blue Men defense value by rolling 3d6. Returns int value generated
//to be used in setDefense() function. Includes logic to reduce number of d6 die
//rolled depending on the current strength of the character.
int BlueMen::actionDefend()
{
    int defValue = 0;
    int roll1 = 0;
    int roll2 = 0;
    int roll3 = 0;

    //3 rolls of d6
    roll1 = (rand() % 6) + 1;
    roll2 = (rand() % 6) + 1;
    roll3 = (rand() % 6) + 1;

    //Full strength, 3d6 rolled for defense
    if (getStrength() <= 12 && getStrength() > 8)
    {
        for (int i = 0; i < 90; i++)
        {
            cout << '~';
        }
        cout << endl;
        cout << "All of the defending Blue Men are alive. Maximum defense." << endl;
        for (int i = 0; i < 90; i++)
        {
            cout << '~';
        }
        cout << endl;
        defValue = roll1 + roll2 + roll3;
    }
    //2/3rds strength, rolls 2d6 for defense
    else if (getStrength() <= 8 && getStrength() > 4)
    {
        for (int i = 0; i < 90; i++)
        {
            cout << '~';
        }
        cout << endl;
        cout << "Some of the defending Blue Men have died. Defense is compromised. " << endl;
        for (int i = 0; i < 90; i++)
        {
            cout << '~';
        }
        cout << endl;
        defValue = roll1 + roll2;
    }
    //1/3 strength, rolls 1d6 for defense
    else if (getStrength() <= 4)
    {
        for (int i = 0; i < 90; i++)
        {
            cout << '~';
        }
        cout << endl;
        cout << "Most of the defending Blue Men have died. Defense is severely compromised." << endl;
        for (int i = 0; i < 90; i++)
        {
            cout << '~';
        }
        cout << endl;
        defValue = roll1;
    }

    return defValue;
}

//Determines if a special attack should be used. This is determined based on the appropriate
//die rolls. Used in playRound() for each Attacker and Defender.
void BlueMen::actionSpecialAttack()
{
}

//Determines if a special defend should be used. This is determined based on the appropriate
//die rolls. Used in playRound() for each Attacker and Defender.
void BlueMen::actionSpecialDefend()
{
}

//Determines if a special other should be used. This is determined based on the appropriate
//die rolls. Used in playRound() for each Attacker and Defender.
void BlueMen::actionSpecialOther()
{
}

//Restores a special ability for the next game if user plays again. Used in fantasy.cpp
void BlueMen::restoreSpecial()
{
}