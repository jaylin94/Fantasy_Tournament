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
#include "character.hpp"
using std::cin;
using std::cout;
using std::endl;

//Restores partial strength for the winning character of a round. Restores the rounded integer value of
//20% of the remaining strength of the character.
void Character::restorePartialStr()
{
    setStrength(getStrength() + ((getStrength() * 10) / 20));
    cout << "Survivor's Strength is now: " << getStrength() << endl;
}