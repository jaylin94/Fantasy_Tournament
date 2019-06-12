#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>

class Character
{
private:
    //String of descriptions
    std::string name;
    std::string charDescrip;
    std::string specialDescrip;
    //String for character type (e.g. "Vampire")
    std::string characterType;
    //Values for combat
    int attack, defense, armor, strength, restoreStrength;

    //Pointers to navigate in a queue
    Character *next;
    Character *prev;

public:
    Character()
    {
        setNext(nullptr);
        setPrev(nullptr);
    }

    //Pure virtual functions to be defined in derived classes with dice rolls
    virtual int actionAttack() = 0;
    virtual int actionDefend() = 0;
    virtual void actionSpecialAttack() = 0;
    virtual void actionSpecialDefend() = 0;
    virtual void actionSpecialOther() = 0;
    virtual void restoreSpecial() = 0;
    virtual void restorePartialStr();

    //Get functions for Character variables
    virtual int getAttack()
    {
        return attack;
    }
    virtual int getDefense()
    {
        return defense;
    }
    virtual int getArmor()
    {
        return armor;
    }
    virtual int getStrength()
    {
        return strength;
    }
    virtual int getRestoreStrength()
    {
        return restoreStrength;
    }
    virtual std::string getCharDescrip()
    {
        return charDescrip;
    }
    virtual std::string getSpecialDescrip()
    {
        return specialDescrip;
    }
    virtual std::string getCharacterType()
    {
        return characterType;
    }
    virtual std::string getName()
    {
        return name;
    }
    virtual Character *getNext()
    {
        return next;
    }
    virtual Character *getPrev()
    {
        return prev;
    }

    //Set functions for Character variables
    virtual void setAttack(int attack)
    {
        this->attack = attack;
    }
    virtual void setDefense(int defense)
    {
        this->defense = defense;
    }
    virtual void setArmor(int armor)
    {
        this->armor = armor;
    }
    virtual void setStrength(int strength)
    {
        this->strength = strength;
    }
    virtual void setRestoreStrength(int restoreStrength)
    {
        this->restoreStrength = restoreStrength;
    }
    virtual void setCharDescrip(std::string charDescrip)
    {
        this->charDescrip = charDescrip;
    }
    virtual void setSpecialDescrip(std::string specialDescrip)
    {
        this->specialDescrip = specialDescrip;
    }
    virtual void setCharacterType(std::string characterType)
    {
        this->characterType = characterType;
    }
    virtual void setName(std::string name)
    {
        this->name = name;
    }
    virtual void setNext(Character *next)
    {
        this->next = next;
    }
    virtual void setPrev(Character *prev)
    {
        this->prev = prev;
    }

    //Virtual destructor
    virtual ~Character()
    {
    }
};

#endif