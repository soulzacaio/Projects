#ifndef GAME_H
#define GAME_H

#include<iostream>

#include "pile.h"
#include "aceFoundation.h"
#include "kingFoundation.h"
#include "deck.h"
#include "wastepile.h"
#include <set>
#include <fstream>



struct printableCard
{
    std::string s = " ";//suit
    std::string t = "  ";//top rank
    std::string b = "  ";//bottom rank
    card *c = NULL;


    std::string colorfy(const card &c, std::string position)
    {
        //R, B & W are Red, Black & White are global const string manipulators to change color of text
        std::ostringstream out;

        std::string color = c.getSuit() == HEARTS || c.getSuit() == DIAMONDS ? R : B;

        if (c.getRank() != TEN)
            if (position == "top")
                out << color << rankStr.at(c.getRank()) << " " << W;
            else
                out << color << " " << rankStr.at(c.getRank()) << W;
        else
            out << color << rankStr.at(c.getRank()) << W;


        return out.str();
    }
    void setupCard(printableCard &pC)
    {
        pC.s = suitStr.at(pC.c->getSuit());
        pC.t = colorfy(*pC.c, "top");
        pC.b = colorfy(*pC.c, "bottom");
    }
    void set(pile *p)
    {
        c = new card(p->getCard());
        setupCard(*this);
    }
    void set(waste<card> &w)
    {
        c = new card(w.getTopCard());
        setupCard(*this);
    }


    ~printableCard() { delete c; }
};


const std::set<std::string> TAGS { "1", "2", "3", "4", "5", "6", "7", "8", "Q", "E", "A", "D", "S" }; // used to check command validity in play()
const std::invalid_argument invalidCommand("You entered an invalid command, nothing was done. You may continue playing.");
const std::invalid_argument kingF_Limitations(G + "King Foundations" + W + " can only play onto the " + M + "Ace Foundation" + W);
const std::invalid_argument doubleKingPlay("No way Jose! That's " + R + "ILLEGAL" + W + ". Once the " + M + "Ace Foundation" + W + " receives a card from a " + G + "King Foundation" + W + ", the next card must come from elsewhere.");
const std::invalid_argument replenishTableaus(Bu + "Tableaus/Sails" + Y + " were replenished from the waste or deck if you had cards available." + W);

class game
{
public:
    game();
    ~game();//!need this? prolly

    bool gameWon();
    //bool hasMoves() const { return availableMoves; }

    void moveHandler(char tag, bool &lastWasKingPlay);
    void moveHandler(char fstTag, char sndTag, bool &lastWasKingPlay);
    void play();
    void draw();
    void redeal();
    void replenishSails();
    std::string inGameHelp(std::string command);

    static std::string read(std::string filename);

    std::string printTable(); //const;

    friend std::ostream &operator<<(std::ostream &out, /* const */ game &g) { return out << g.printTable(); };

private:
    bool won;

    deck<card> d;//deck
    waste<card> w;//wastepile
    pile *aceF;//Ace Foundation
    pile *tL;//Top Left King Foundation
    pile *tR;//Top Right King Foundation
    pile *bL;//Bottom Left King Foundation
    pile *bR;//Bottom Right King Foundation
    pile **tP;//Dynamic Array containing 8 tableau piles

};
std::string tag(std::string tag, std::string color);
std::string colorfy(std::string str, std::string color);
void toUpper(std::string &x);



#endif

/*
==========================REPRESENTATION OF GAME SET UP AND CLASS MEMBERS=========================
NOTE: for the dynamic array, i'll make it one size larger so first tableau pile is tP[1] instead of tp[0]
tP[0] will be initialized as the others, but to an empty state using the default constructor

tableau piles are numbered from top to bottom, left to right as shown below:
---------Game Table

               [tP1]

       [tL ]   [tP2]  [tR ]

[tP3]  [tP4]   [ A ]   [tP5]  [tP6]

       [bL ]   [tP7]  [bR ]

               [tP8]
 */