#include "card.h"

//=================================================================================================CARD IMPLEMENTATION
card::card(RANK rank, SUIT suit, int color)
{
    this->rank = static_cast<RANK>(rank);
    this->suit = static_cast<SUIT>(suit);
    isRed = color == 1 ? true : false;
}
//Getters
SUIT card::getSuit() const { return this->suit; }
RANK card::getRank() const { return this->rank; }




