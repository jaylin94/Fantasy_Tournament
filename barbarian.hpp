#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include <string>
#include "character.hpp"

class Barbarian : public Character
{
public:
    Barbarian()
    {
        setCharDescrip("Think Conan or Hercules from the movies. Big sword, big muscles, bare torso.");
        setSpecialDescrip("None. Muscles are all you need.");
        setCharacterType("Barbarian");
        setArmor(0);
        setStrength(12);
        setRestoreStrength(12);
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