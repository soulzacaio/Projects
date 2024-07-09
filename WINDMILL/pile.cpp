#include "pile.h"
#include <iostream>

pile::pile()
{
    cards = nullptr;
    count = 0;
}
pile::pile(deck<card> &deck)
{
    count = 1;
    cards = new card * [count];
    cards[0] = new card(deck.pop());
}
pile::~pile()
{
    for (int i = 0; i < count; i++)
        delete cards[i];
    delete [] cards;
}

const card pile::getCard() const
{
    if (isEmpty())
        throw std::invalid_argument(Bu + "Tableau/Sail" + W + " is empty, there's no card to play.");

    return *cards[count - 1];
}

card pile::popCard()
{
    if (isEmpty())
        throw std::invalid_argument(Bu + "Tableau/Sail" + W + " is empty, there is nothing there to play.");

    card retCard = getCard();

    count--;
    card **temp;

    if (!isEmpty())
    {
        temp = new card * [count];

        for (int i = 0; i < count; i++)
            temp[i] = new card(*cards[i]);

        for (int i = 0; i < count + 1; i++)
            delete cards[i];

        delete [] cards;

        cards = temp;
    }
    else
    {
        //empty = true;
        delete cards[0];
        delete [] cards;
        cards = nullptr;
    }

    return retCard;
}

void pile::addCard(card newCard)
{
    //std::cout << "NOT USING POLY" << std::endl;
    if (!isEmpty())
        throw std::invalid_argument(Bu + "Tableaus/Sails" + W + " must be empty for you to play onto it");

    count++;
    cards = new card * [count];
    cards[0] = new card(newCard);
}

void pile::operator+(deck<card> &d)
{
    addCard(d.top());
    d.pop();
}

void pile::operator+(pile *p)
{
    addCard(p->getCard());
    p->popCard();
}

void pile::operator+(waste<card> &w)
{
    addCard(w.getTopCard());
    --w;
}


