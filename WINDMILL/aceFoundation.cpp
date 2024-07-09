#include "aceFoundation.h"
#include <iostream>



aceFoundation::aceFoundation(deck<card> &d)
{
    count = 1;
    cards = new card * [count];
    cards[0] = new card(d.getAce(card::isAce));
    //kingPlay = false;
}
//adds card to pile if conditions are met
void aceFoundation::addCard(card newCard)
{

    //gives user tip of what card can be played after an invalid move is attempted
    std::string playableCard = this->getCard().getRank() == KING ? "Ace" : rankStr.at(static_cast<RANK>(this->getCard().getRank() + 1));

    if (!canReceive(newCard))
        throw std::invalid_argument("Invalid move, " + M + "Ace Foundation" + W + " build up in rank. You could play a(n) " + playableCard + " here if you have one.");


    if (!isFull())
    {
        int oldBound = count;
        count++;

        card **temp = new card * [count];

        for (int i = 0; i < oldBound; i++)
        {
            temp[i] = new card(*cards[i]);
            delete cards[i];
        }
        temp[oldBound] = new card(newCard);

        delete [] cards;
        cards = NULL;
        cards = temp;
    }
    else
        throw std::invalid_argument("Invalid move, " + M + "Ace Foundation" + W + " is full, you must work on your " + G + "King Foundations" + W + " now.");
}

//checks card on top for validity of play
bool aceFoundation::canReceive(card newCard)
{
    card topCard = getCard();

    if (topCard.getRank() == KING)
        if (newCard.getRank() != ACE)
            return false;
        else
            return true;

    if (newCard.getRank() != topCard.getRank() + 1)
        return false;

    return true;
}

const card aceFoundation::getCard() const
{
    return pile::getCard();
}
