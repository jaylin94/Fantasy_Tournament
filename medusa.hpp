#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include <string>
#include "character.hpp"

class Medusa : public Character
{
public:
    Medusa()
    {
        setCharDescrip("Scrawny lady with snakes for hair which helps her during combat. Just don’t look at her!");
        setSpecialDescrip("Glare: If a Medusa rolls a 12 when attacking then the target instantly gets turned into stone and Medusa wins! If Medusa uses Glare on Harry Potter on his first life, then Harry Potter comes back to life.");
        setCharacterType("Medusa");
        setArmor(3);
        setStrength(8);
        setRestoreStrength(8);
        setNext(nullptr);
        setPrev(nullptr);
    }

    int actionAttack();
    int actionDefend();
    void actionSpecialAttack();
    void actionSpecialDefend();
    void actionSpecialOther();
    void restoreSpecial();
};

#endif