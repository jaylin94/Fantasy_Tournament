#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <string>
#include "character.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "bluemen.hpp"
#include "medusa.hpp"
#include "harryPotter.hpp"

class Queue
{
private:
    //Head pointer
    Character *head;
    //Score for teams
    int score;

public:
    Queue()
    {
        setHead(nullptr);
        setScore(0);
    }

    //Adds character pointer/derived character objects to the back of the queue
    void addBack(int userChoice, int charCount, int charNum, Vampire *vampire, Barbarian *barbarian, BlueMen *blueMen, Medusa *medusa, HarryPotter *harryPotter);
    void addBackLoser(Character *loserChar);

    //Gets last pointer in the queue
    Character *getEnd();

    //Rotates team of characters so that first character is now last
    void rotate();

    //Delete functions
    void removeFront();
    void deleteFront();
    void loserDelete();
    void dealloc();

    //Print functions
    void printQueue();
    void revPrintQueue();

    //Determines if a queue is empty
    bool isEmpty();

    //Get functions
    Character *getHead()
    {
        return head;
    }
    int getScore()
    {
        return score;
    }

    //Set functions
    void setHead(Character *head)
    {
        this->head = head;
    }
    void setScore(int score)
    {
        this->score = score;
    }
};

#endif