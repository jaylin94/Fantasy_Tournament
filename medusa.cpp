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
#include "medusa.hpp"
using std::cin;
using std::cout;
using std::endl;

//Generates Medusa attack value by rolling 2d10. Returns int value generated
//to be used in setAttack() function. Includes logic to cast Glare and instantly
//kill the opposing character.
int Medusa::actionAttack()
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

//Generates Medusa defense value by rolling 1d6. Returns int value generated
//to be used in setDefense() function.
int Medusa::actionDefend()
{
    int defValue = 0;
    int roll1 = 0;

    //1 rolls of d6
    roll1 = (rand() % 6) + 1;
    defValue = roll1;

    return defValue;
}

//Determines if a special attack should be used. This is determined based on the appropriate
//die rolls. Used in playRound() for each Attacker and Defender. Glare is cast if 2 6's are
//rolled and instantly kills the defender unless it is a vampire that casts glare or
//harry potter that has hogwarts.
void Medusa::actionSpecialAttack()
{
    //Determines if Glare is cast on Medusa's opponent, 2 6's must be rolled
    if (getAttack() == 12)
    {
        setAttack(100);
        for (int i = 0; i < 90; i++)
        {
            cout << '~';
        }
        cout << endl;
        cout << "The attacking Medusa has caught the defender's gaze! The defender turns into STONE!" << endl;
        for (int i = 0; i < 90; i++)
        {
            cout << '~';
        }
        cout << endl;
    }
}

//Determines if a special defend should be used. This is determined based on the appropriate
//die rolls. Used in playRound() for each Attacker and Defender.
void Medusa::actionSpecialDefend()
{
}

//Determines if a special other should be used. This is determined based on the appropriate
//die rolls. Used in playRound() for each Attacker and Defender.
void Medusa::actionSpecialOther()
{
}

//Restores a special ability for the next game if user plays again. Used in fantasy.cpp
void Medusa::restoreSpecial()
{
}
