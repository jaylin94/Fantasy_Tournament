#ifndef GAME_HPP
#define GAME_HPP
#include "character.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "bluemen.hpp"
#include "medusa.hpp"
#include "harryPotter.hpp"
#include "queue.hpp"

class Game
{
private:
    //Character pointers for game implementation
    Character *player1;
    Character *player2;
    Character *attacker;
    Character *defender;

    //Queue pointers for team containers and loser container
    Queue *pTeam1;
    Queue *pTeam2;
    Queue *pLosers;

    //Stores player number and round count
    int playerNum;
    int roundNum;
    int charCount;
    int charNum;

public:
    Game()
    {
        setCharNum(0);
        setRoundNum(1);
        setCharCount(1);
    }

    //Play round function, each team attacks
    void playRound(Game *pGame);

    //Display functions
    void displayLine(int type);
    void displayContinue();

    //Get functions for Game class variables
    Queue *getTeam1()
    {
        return pTeam1;
    }
    Queue *getTeam2()
    {
        return pTeam2;
    }
    Queue *getLosers()
    {
        return pLosers;
    }
    Character *getPlayer1()
    {
        return player1;
    }
    Character *getPlayer2()
    {
        return player2;
    }
    Character *getAttacker()
    {
        return attacker;
    }
    Character *getDefender()
    {
        return defender;
    }
    int getPlayerNum()
    {
        return playerNum;
    }
    int getRoundNum()
    {
        return roundNum;
    }
    int getCharCount()
    {
        return charCount;
    }
    int getCharNum()
    {
        return charNum;
    }

    //Set functions for Game class variables
    void setTeam1(Queue *pTeam1)
    {
        this->pTeam1 = pTeam1;
    }
    void setTeam2(Queue *pTeam2)
    {
        this->pTeam2 = pTeam2;
    }
    void setLosers(Queue *pLosers)
    {
        this->pLosers = pLosers;
    }
    void setPlayer1(Character *player1)
    {
        this->player1 = player1;
    }
    void setPlayer2(Character *player2)
    {
        this->player2 = player2;
    }
    void setAttacker(Character *attacker)
    {
        this->attacker = attacker;
    }
    void setDefender(Character *defender)
    {
        this->defender = defender;
    }
    void setPlayerNum(int playerNum)
    {
        this->playerNum = playerNum;
    }
    void setRoundNum(int roundNum)
    {
        this->roundNum = roundNum;
    }
    void setCharCount(int charCount)
    {
        this->charCount = charCount;
    }
    void setCharNum(int charNum)
    {
        this->charNum = charNum;
    }
};

#endif