#ifndef PILE_H
#define PILE_H

#include "card.h"
#include <stdexcept>
#include "deck.h"
#include "wastepile.h"

class pile
{
public:
    pile();//!do i need this? 
    pile(deck<card> &);
    ~pile();

    virtual const card getCard() const;
    card popCard();

    virtual void addCard(card newCard);
    bool isEmpty() const { return count == 0; }
    virtual bool isFull() const { return count == 1; };
    virtual bool canReceive(card newCard) { return isEmpty(); };//to be implemented in children

    void operator--() { popCard(); } //!don't think i need this
    void operator+(deck<card> &);
    void operator+(pile *p);
    void operator+(waste<card> &);


protected:

    card **cards;
    int count;
};
#endif