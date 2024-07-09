#ifndef DECK_H
#define DECK_H

#include <stdexcept>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "card.h"

#include <sstream>

#include <iostream>

template <class t>
struct node
{
    t *data;
    node<t> *link;
    ~node()
    {
        delete data;
    }
};

template <typename t>
class deck //: public stackADT<t>
{
public:
    deck();
    deck(const deck<t> &otherStack);
    ~deck() { initializeStack(); };
    bool isEmptyStack() const { return this->sTop == nullptr; };
    deck<t> &operator=(const deck<t> &);
    t getAce(bool (*findAceInDeck)(const t &));
    int size() const { return count; };


    void initializeStack();
    t pop();
    t top() const;
    void push(const t &);

private:
    int count;
    node<t> *sTop; // Stack Top
};



template <typename t>
deck<t>::deck()
{
    this->sTop = nullptr;
    this->count = 0;
    std::vector<t> v;

    for (int i = 0; i < 2; i++)
        for (int suit = HEARTS; suit <= SPADES; suit++)
            for (int rank = ACE; rank <= KING; rank++)
                v.push_back(t(static_cast<RANK>(rank), static_cast<SUIT>(suit), i));




    std::srand(std::time(NULL));
    int k;
    //shuffle 7 times as the Card Guy recommends
    for (int w = 0; w < 8; w++)
        for (int i = v.size() - 1; i > 0; i--)//Fisher-Yates shuffle algorithm again!
        {
            k = std::rand() % (i + 1);
            std::swap(v[i], v[k]);
        }
    for (t cardInVector : v)
        this->push(cardInVector);
}

template<typename t>
t deck<t>::getAce(bool (*foundAceInDeck)(const t &thisCard))
{
    //*no need to check for empty or if current is NULL since its garanteed
    //*there are 8 aces in the deck,
    //*the only special case is when the ace is at the top
    node<t> *current;
    node<t> *trail;
    if (foundAceInDeck(*(this->sTop->data)))
    {
        current = this->sTop;
        this->sTop = this->sTop->link;
        this->count--;
        t foundAce = *(current->data);
        delete current;
        return foundAce;
    }
    else
    {
        trail = this->sTop;
        current = this->sTop->link;
        while (!foundAceInDeck(*(current->data)))
        {
            trail = current;
            current = current->link;
        }
        t foundAce = *(current->data);
        trail->link = current->link;
        delete current;
        count--;
        return foundAce;
    }
}


//-------------------------------------------------------------------------------------------------
template <typename t>
t deck<t>::top() const
{
    // make sure its not empty
    if (this->sTop == nullptr)
        throw std::out_of_range("Deck is empty, there's nothing at the top.[top()]");

    return *(this->sTop->data);
}
//-------------------------------------------------------------------------------------------------
template <typename t>
void deck<t>::push(const t &newElem)
{

    node<t> *newNode = new node<t>; // build new node

    newNode->data = new t(newElem); // make new obk with newElem and assign it to data in newNode
    newNode->link = this->sTop;     // make newNode the new head(top)
    this->sTop = newNode;           // update top to point to newly inserted elem
    this->count++;
}
//-------------------------------------------------------------------------------------------------
template <typename t>
t deck<t>::pop()
{
    if (this->sTop == nullptr)
        throw std::underflow_error("Can't remove from an empty stack.[pop()]");

    node<t> *temp;
    // t elemToPop;

    t elemToPop = *(sTop->data);   // make a copy of the initial top's data
    temp = this->sTop;             // assign temp node to store top location, so sTop doesnt dangle
    this->sTop = this->sTop->link; // advance top down the stack
    delete temp;                   // delete what was the initially the top

    this->count--;
    return elemToPop;
}

//-------------------------------------------------------------------------------------------------
template <typename t>
deck<t> &deck<t>::operator=(const deck<t> &otherStack)
{
    if (this != &otherStack) // check if address is equal(same stack), if not, copy other and return
        copyStack(otherStack);
    return *this;
}

//-------------------------------------------------------------------------------------------------
template <typename t>
deck<t>::deck(const deck<t> &otherStack)
{
    this->sTop = nullptr;
    copyStack(otherStack);
}
//-------------------------------------------------------------------------------------------------
template <typename t>
void deck<t>::initializeStack()
{
    node<t> *temp; // place holder
    while (this->sTop != nullptr)
    {
        temp = this->sTop;             // assign top to temp
        this->sTop = this->sTop->link; // move top down
        delete temp;                   // delete place holder carrying original top
    }
    this->count = 0;
}


#endif
