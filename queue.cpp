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
#include "queue.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

//Prints the entire queue of list values. Will print error message if the list is empty.
//Contains logic for one Character, two Characters, or more than two Characters .
void Queue::printQueue()
{
    Character *temp = getHead();

    //If empty, output empty message
    if (isEmpty() == true)
    {
        cout << "The queue is empty." << endl;
        return;
    }
    //If not empty, print queue
    else if (isEmpty() == false)
    {
        cout << "Your character list: ";
        //If there is only one Character print head
        if (getHead()->getPrev() == nullptr && getHead()->getNext() == nullptr)
        {
            cout << getHead()->getName() << endl;
            return;
        }
        else if (getHead()->getPrev() == getHead()->getNext())
        {
            cout << getHead()->getName();
            cout << " ";
            cout << getHead()->getNext()->getName();
            cout << endl;
            return;
        }
        //If there are more than two Characters, print all
        else if (getHead()->getNext() != getHead()->getPrev())
        {
            cout << getHead()->getName();
            //Traverse circular linked list and print all values
            while (temp->getNext() != getHead())
            {
                cout << " ";
                cout << temp->getNext()->getName();
                temp = temp->getNext();
            }
            cout << endl;
            return;
        }
    }
}

void Queue::revPrintQueue()
{
    Character *temp = getEnd();

    //If empty, output empty message
    if (isEmpty() == true)
    {
        cout << "The queue is empty." << endl;
        return;
    }
    //If not empty, print queue
    else if (isEmpty() == false)
    {
        cout << "Your character list: ";
        //If there is only one Character print head
        if (getHead()->getPrev() == nullptr && getHead()->getNext() == nullptr)
        {
            cout << getHead()->getName() << endl;
            return;
        }
        //Prints if there are two Characters
        else if (getHead()->getPrev() == getHead()->getNext())
        {
            cout << getHead()->getNext()->getName();
            cout << " ";
            cout << getHead()->getName();
            cout << endl;
            return;
        }
        //If there are more than two Characters, print all
        else if (getHead()->getNext() != getHead()->getPrev())
        {
            cout << getEnd()->getName();
            cout << " ";
            //Traverse circular linked list and print all values
            while (temp->getPrev() != getHead())
            {
                cout << temp->getPrev()->getName();
                cout << " ";
                temp = temp->getPrev();
            }
            cout << getHead()->getName();
            cout << endl;
            return;
        }
    }
}

//Adds a Character pointer to the back of the list. Takes an integer parameter
//to set for the new Node value. Called in menuChoice().
void Queue::addBack(int userChoice, int charCount, int charNum, Vampire *vampire, Barbarian *barbarian, BlueMen *blueMen, Medusa *medusa, HarryPotter *harryPotter)
{
    Character **pCharacter = new Character *;

    //Depending on user selection, sets pointer to point to derived character object
    switch (userChoice)
    {
    case 1:
        *pCharacter = (&vampire[charCount - charNum]);
        break;
    case 2:
        *pCharacter = (&barbarian[charCount - charNum]);
        break;
    case 3:
        *pCharacter = (&blueMen[charCount - charNum]);
        break;
    case 4:
        *pCharacter = (&medusa[charCount - charNum]);
        break;
    case 5:
        *pCharacter = (&harryPotter[charCount - charNum]);
        break;
    }

    //Holds HEAD temporarily
    Character *temp = getHead();

    //If list is empty, set head to new node, set getPrev() and getNext() to nullptr
    if (isEmpty() == true)
    {
        setHead(*pCharacter);
        getHead()->setPrev(nullptr);
        getHead()->setNext(nullptr);
        delete pCharacter;
        return;
    }
    // If list is not empty
    else if (isEmpty() == false)
    {
        //If there is one node set new node to head->getNext()
        if (getHead()->getPrev() == nullptr && getHead()->getNext() == nullptr)
        {
            getHead()->setNext(*pCharacter);
            (*pCharacter)->setPrev(getHead());
            (*pCharacter)->setNext(getHead());
            getHead()->setPrev(*pCharacter);
            delete pCharacter;
            return;
        }
        //If there are two nodes, append 3rd node
        else if (getHead()->getPrev() == getHead()->getNext())
        {
            temp = getHead()->getNext();
            temp->setNext(*pCharacter);
            (*pCharacter)->setPrev(temp);
            (*pCharacter)->setNext(getHead());
            getHead()->setPrev(*pCharacter);
            delete pCharacter;
            return;
        }
        //If more than one node, append new node to last node
        else
        {
            //Traverse all nodes and append new node
            while (temp->getNext() != getHead())
            {
                temp = temp->getNext();
            }
            temp->setNext(*pCharacter);
            (*pCharacter)->setPrev(temp);
            (*pCharacter)->setNext(getHead());
            getHead()->setPrev(*pCharacter);
            delete pCharacter;
            return;
        }
    }
}

//Adds a loser to the back of the loser container. Takes a character object pointer, sets the name of the new
//object to the name of the pointer passed into the function.
void Queue::addBackLoser(Character *loserChar)
{
    //Gets the name of the loser character
    string charType = loserChar->getCharacterType();

    //Pointer to point to new derived character object
    Character *pCharacter = nullptr;

    //Allocates new character object and sets name to loser name
    if (charType == "Vampire")
    {
        pCharacter = new Vampire;
        pCharacter->setName(loserChar->getName());
    }
    else if (charType == "Barbarian")
    {
        pCharacter = new Barbarian;
        pCharacter->setName(loserChar->getName());
    }
    else if (charType == "Blue Men")
    {
        pCharacter = new BlueMen;
        pCharacter->setName(loserChar->getName());
    }
    else if (charType == "Medusa")
    {
        pCharacter = new Medusa;
        pCharacter->setName(loserChar->getName());
    }
    else if (charType == "Harry Potter")
    {
        pCharacter = new HarryPotter;
        pCharacter->setName(loserChar->getName());
    }
    Character *temp = getHead();

    //If list is empty, set head to new node, set getPrev() and getNext() to nullptr
    if (isEmpty() == true)
    {
        setHead(pCharacter);
        getHead()->setPrev(nullptr);
        getHead()->setNext(nullptr);
        return;
    }
    // If list is not empty
    else if (isEmpty() == false)
    {
        //If there is one node set new node to head->getNext()
        if (getHead()->getPrev() == nullptr && getHead()->getNext() == nullptr)
        {
            getHead()->setNext(pCharacter);
            (pCharacter)->setPrev(getHead());
            (pCharacter)->setNext(getHead());
            getHead()->setPrev(pCharacter);
            return;
        }
        //If there are two nodes, append 3rd node
        else if (getHead()->getPrev() == getHead()->getNext())
        {
            temp = getHead()->getNext();
            temp->setNext(pCharacter);
            (pCharacter)->setPrev(temp);
            (pCharacter)->setNext(getHead());
            getHead()->setPrev(pCharacter);
            return;
        }
        //If more than one node, append new node to last node
        else
        {
            //Traverse all nodes and append new node
            while (temp->getNext() != getHead())
            {
                temp = temp->getNext();
            }
            temp->setNext(pCharacter);
            (pCharacter)->setPrev(temp);
            (pCharacter)->setNext(getHead());
            getHead()->setPrev(pCharacter);
            return;
        }
    }
}

//Returns the last object in the queue/container, takes no parameters.
//Returns a Character pointer
Character *Queue::getEnd()
{
    Character *temp = getHead();

    //Empty, print empty message.
    if (isEmpty() == true)
    {
        cout << "The character queue is empty." << endl;
    }
    //Not empty, return approriate pointer.
    else if (isEmpty() == false)
    {
        //1 Character in queue
        if (getHead()->getPrev() == nullptr && getHead()->getNext() == nullptr)
        {
            return getHead();
        }
        //2 Characters in queue
        else if (getHead()->getPrev() == getHead()->getNext())
        {
            return getHead()->getNext();
        }
        //More than 2 Characters in queue
        else if (getHead()->getNext() != getHead()->getPrev())
        {
            while (temp->getNext() != getHead())
            {
                temp = temp->getNext();
            }
            return temp;
        }
    }
    return getHead();
}

//Rotates queue of Character objects if more than 1 Character.
void Queue::rotate()
{
    Character *temp = getHead();
    Character *temp2 = getHead();

    //Empty queue, return
    if (isEmpty() == true)
    {
        return;
    }
    //Not empty queue, rotate accordingly
    else if (isEmpty() == false)
    {
        //1 Character, return
        if (getHead()->getNext() == nullptr && getHead()->getPrev() == nullptr)
        {
            return;
        }
        //2 Characters, rotate
        else if (getHead()->getPrev() == getHead()->getNext())
        {
            setHead(temp->getNext());
            getHead()->setPrev(temp);
            getHead()->setNext(temp);
            temp->setNext(getHead());
            temp->setPrev(getHead());
            return;
        }
        //3 or more Characters, rotate
        else if (getHead()->getPrev() != getHead()->getNext())
        {
            while (temp2->getNext() != getHead())
            {
                temp2 = temp2->getNext();
            }
            setHead(temp->getNext());
            getHead()->setPrev(temp);
            getHead()->setNext(getHead()->getNext());
            temp->setNext(getHead());
            temp->setPrev(temp2);
            return;
        }
    }
}

//Removes the HEAD of the node, sets it to nullptr
//Sets all other pointers accordingly.
void Queue::removeFront()
{
    Character *temp = getHead();
    if (isEmpty() == true)
    {
        cout << "The list is empty. " << endl;
        return;
    }
    //If list is not empty
    else if (isEmpty() == false)
    {
        //If there is one node, delete it, set HEAD to nullptr
        if (getHead()->getNext() == nullptr && getHead()->getPrev() == nullptr)
        {
            setHead(nullptr);
            return;
        }
        //If there are 2 nodes
        else if (getHead()->getNext() == getHead()->getPrev())
        {
            setHead(temp->getNext());
            getHead()->setNext(nullptr);
            getHead()->setPrev(nullptr);
            temp = nullptr;
            return;
        }
        //If there are more than 2 nodes, set getPrev() and getNext() accordingly
        else if (getHead()->getNext() != getHead()->getPrev())
        {
            setHead(temp->getNext());
            getHead()->setPrev(temp->getPrev());
            temp->getPrev()->setNext(getHead());
            temp = nullptr;
            return;
        }
    }
}

//Removes the HEAD of the node and sets the HEAD to the old head->getNext()
//Sets all other pointers accordingly.
void Queue::deleteFront()
{
    Character *temp = getHead();
    if (isEmpty() == true)
    {
        cout << "The list is empty. " << endl;
        return;
    }
    //If list is not empty
    else if (isEmpty() == false)
    {
        //If there is one node, delete it, set HEAD to nullptr
        if (getHead()->getNext() == nullptr && getHead()->getPrev() == nullptr)
        {
            delete getHead();
            setHead(nullptr);
            return;
        }
        //If there are 2 nodes, delete first node
        else if (getHead()->getNext() == getHead()->getPrev())
        {
            setHead(temp->getNext());
            getHead()->setNext(nullptr);
            getHead()->setPrev(nullptr);
            delete temp;
            return;
        }
        //If there are more than 2 nodes, delete first node, set getPrev() and getNext() accordingly
        else if (getHead()->getNext() != getHead()->getPrev())
        {
            setHead(temp->getNext());
            getHead()->setPrev(temp->getPrev());
            temp->getPrev()->setNext(getHead());
            delete temp;
            return;
        }
    }
}

//Returns a bool value of true of the list is empty, determined with getHead() == nullptr.
//Returns a bool value of false if list is not empty.
bool Queue::isEmpty()
{
    if (getHead() == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Sets all nodes to nullptr if tournament is being rerun. Clears containers for team1, team2, losers.
void Queue::dealloc()
{
    Character *temp;

    if (isEmpty() == true)
    {
        return;
    }
    else if (isEmpty() == false)
    {
        //If there is one node, delete it and return
        if (getHead()->getNext() == nullptr && getHead()->getPrev() == nullptr)
        {
            setHead(nullptr);
            return;
        }
        //If there are two or more nodes, delete all nodes
        while (getHead()->getNext() != getHead()->getPrev())
        {
            temp = getHead();
            setHead(temp->getNext());
            getHead()->setPrev(temp->getPrev());
            temp = nullptr;
        }
        //Delete the 2nd to last node and last node
        if (getHead()->getNext() == getHead()->getPrev())
        {
            temp = getHead();
            setHead(getHead()->getNext());
            getHead()->setNext(nullptr);
            getHead()->setPrev(nullptr);
            setHead(nullptr);
            temp = nullptr;
        }
    }
}

//Deletes loser objects that were allocated in addBackLosers(). Sets all pointers to nullptr.
void Queue::loserDelete()
{
    Character *temp;

    if (isEmpty() == true)
    {
        return;
    }
    else if (isEmpty() == false)
    {
        //If there is one node, delete it and return
        if (getHead()->getNext() == nullptr && getHead()->getPrev() == nullptr)
        {
            delete getHead();
            setHead(nullptr);
            return;
        }
        //If there are two or more nodes, delete all nodes
        while (getHead()->getNext() != getHead()->getPrev())
        {
            temp = getHead();
            setHead(temp->getNext());
            getHead()->setPrev(temp->getPrev());
            delete temp;
            temp = nullptr;
        }
        //Delete the 2nd to last node and last node
        if (getHead()->getNext() == getHead()->getPrev())
        {
            temp = getHead();
            setHead(getHead()->getNext());
            getHead()->setNext(nullptr);
            getHead()->setPrev(nullptr);
            delete temp;
            delete getHead();
            setHead(nullptr);
            temp = nullptr;
        }
    }
}
