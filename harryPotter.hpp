#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include <string>
#include "character.hpp"

class HarryPotter : public Character
{
private:
    int hogwarts;

public:
    HarryPotter()
    {
        setCharDescrip("Harry Potter is a wizard.");
        setSpecialDescrip("Hogwarts: If Harry Potter's strength reaches 0 or below, he immediately recovers and his total strength becomes 20. If he were to die again, then he’s dead.");
        setCharacterType("Harry Potter");
        setArmor(0);
        setStrength(10);
        setRestoreStrength(10);
        setHogwarts(0);
        setNext(nullptr);
        setPrev(nullptr);
    }

    int actionAttack();
    int actionDefend();
    void actionSpecialAttack();
    void actionSpecialDefend();
    void actionSpecialOther();
    void restoreSpecial();

    //Get function for Hogwarts
    int getHogwarts()
    {
        return hogwarts;
    }

    //Set function for Hogwarts
    void setHogwarts(int hogwarts)
    {
        this->hogwarts = hogwarts;
    }
};

#endif