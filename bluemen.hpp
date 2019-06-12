#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include <string>
#include "character.hpp"

class BlueMen : public Character
{
public:
    BlueMen()
    {
        setCharDescrip("They are small, 6 inch tall, but fast and tough. They are hard to hit so they can take some damage. They can also do a LOT of damage when they crawl inside enemies’ armor or clothing.");
        setSpecialDescrip("Mob: Blue Men are actually a swarm of small individuals. For every 4 points of damage, they lose one defense die. For example, if they have a strength of 8, they would have 2d6 for defense.");
        setCharacterType("Blue Men");
        setArmor(3);
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