#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include <string>
#include "character.hpp"

class Vampire : public Character
{
public:
    Vampire()
    {
        setCharDescrip("Suave, debonair, but vicious and surprisingly resilient.");
        setSpecialDescrip("Charm: Vampires can charm an opponent into not attacking. For a given attack there is a 50% chance that their opponent does not actually attack them.");
        setCharacterType("Vampire");
        setArmor(1);
        setStrength(18);
        setRestoreStrength(18);
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