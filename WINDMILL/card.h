#ifndef CARD_H
#define CARD_H

#include <string>
#include <map>





//string manipulators for colored text, used throughout the program
const std::string B = "\033[30m";//black
const std::string R = "\033[31m";//red
const std::string Y = "\033[33m";//yellow
const std::string G = "\033[32m";//green
const std::string Bu = "\033[34m";//blue
const std::string M = "\033[35m";//magenta
const std::string C = "\033[36m";//cyan
const std::string W = "\033[0m";//default


enum SUIT { HEARTS, DIAMONDS, CLUBS, SPADES };
//SUIT operator++(SUIT &s);

enum RANK { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
//RANK operator++(RANK &r);

const std::map<SUIT, std::string> suitStr
{
    {HEARTS,   R + "♥" + W},
    {DIAMONDS, R + "♦" + W},
    {CLUBS,    B + "♣" + W},
    {SPADES,   B + "♠" + W}

};
const std::map<RANK, std::string> rankStr
{
    {ACE ,  "A"},
    {TWO,   "2"},
    {THREE, "3"},
    {FOUR,  "4"},
    {FIVE,  "5"},
    {SIX,   "6"},
    {SEVEN, "7"},
    {EIGHT, "8"},
    {NINE,  "9"},
    {TEN,   "10"},
    {JACK,  "J"},
    {QUEEN, "Q"},
    {KING,  "K"},
};

class card
{
public:

    //Constr.
    card(RANK rank, SUIT suit, int color);

    //Getters
    RANK getRank() const;
    SUIT getSuit() const;
    bool getColor() const { return isRed; };

    static bool isAce(const card &c) { return c.rank == ACE; };



private:
    //Members
    RANK rank;
    SUIT suit;
    bool isRed;

};

#endif