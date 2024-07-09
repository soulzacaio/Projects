#include "kingFoundation.h"
#include <iostream>

void kingFoundation::addCard(card newCard)
{
    if (isRetired())
        throw std::invalid_argument("This " + G + "King Foundation" + W + " is retired, playing here is not allowed.");

    std::string playableCard;
    if (!isEmpty())
        playableCard = rankStr.at(static_cast<RANK>(this->getCard().getRank() - 1));

    if (!canReceive(newCard))
        throw std::invalid_argument("Invalid move, " + G + "King Foundations" + W + " build down in rank. You could play a(n) " + playableCard + " here if you have one.");


    if (isEmpty())
    {
        cards = new card * [++count];
        cards[count - 1] = new card(newCard);
    }
    else
    {
        card **temp = new card * [++count];

        for (int i = 0; i < count - 1; i++)
        {
            temp[i] = new card(*cards[i]);
            delete cards[i];
        }
        temp[count - 1] = new card(newCard);

        delete [] cards;
        cards = NULL;
        cards = temp;
    }

}

bool kingFoundation::canReceive(card newCard)
{
    if (isEmpty())
        if (newCard.getRank() != KING)
            throw std::invalid_argument("Invalid play, " + G + "King Foundations" + W + " must start with a... King");
        else
            return true;
    else
    {
        card topCard = getCard();

        if (newCard.getRank() != topCard.getRank() - 1)
            return false;
        return true;
    }
}

const card kingFoundation::getCard() const
{
    try
    {
        return pile::getCard();
    }
    catch (...)
    {
        throw std::invalid_argument("This " + G + "King Foundation" + W + " is empty. There's no card to play.");
    }
}
