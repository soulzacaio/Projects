#include "game.h"


game::game()
{
    won /* = availableMoves */ = false;
    tL = new kingFoundation();
    tR = new kingFoundation();
    bL = new kingFoundation();
    bR = new kingFoundation();
    aceF = new aceFoundation(d);

    tP = new pile * [9];//extra size so [0] can be empty
    tP[0] = new pile;//empty pile, has no data, nor cards

    for (int i = 1; i < 9; i++)
        tP[i] = new pile(d);
}

game::~game()
{

    delete tL;
    delete tR;
    delete bL;
    delete bR;
    delete aceF;
    for (int i = 0; i < 9; i++)
        delete tP[i];
    delete [] tP;
}

bool game::gameWon()
{
    //as long as the aceFoundation and all King Foundations are full, the piles will have no cards and game is won
    return aceF->isFull() && tL->isFull() && tR->isFull() && bL->isFull() && bR->isFull();
}

std::string game::read(std::string filename)
{
    std::ostringstream out;
    std::ifstream readFile;

    readFile.open(filename + ".txt");

    if (!readFile.is_open())
        std::cerr << "Unable to find " + filename + ".txt file" << std::endl;

    std::string line;

    while (std::getline(readFile, line))
        out << line << std::endl;

    readFile.close();

    return out.str();
}



void game::moveHandler(char destination, bool &lastWasKingPlay)
{

    //this is for playing directly from the wastepile to any other pile, validation of moves is done internally in the pile classes
    //when a pile receives a card it can't accept, it throws an exception to be handled in main

    int destInt = destination - '0';

    switch (destination)
    {

        //cases 1-8 are plays onto tableaus
        case '1': *tP[destInt] + w; break;
        case '2': *tP[destInt] + w; break;
        case '3': *tP[destInt] + w; break;
        case '4': *tP[destInt] + w; break;
        case '5': *tP[destInt] + w; break;
        case '6': *tP[destInt] + w; break;
        case '7': *tP[destInt] + w; break;
        case '8': *tP[destInt] + w; break;

            //cases Q, E, A, D are plays onto king foundations
        case 'Q': *tL + w; break;
        case 'E': *tR + w; break;
        case 'A': *bL + w; break;
        case 'D': *bR + w; break;

            //playing onto ace foundation
        case 'S':
            *aceF + w;
            lastWasKingPlay = false;
            break;

        default: throw invalidCommand;
    }
}

void game::moveHandler(char origin, char destination, bool &lastWasKingPlay)
{
    //used to control whether last play onto Ace Foundation came from a King Foundation
    //static bool lastWasKingPlay = false;
    int originInt = origin - '0';

    switch (origin)
    {
        //*the numberes cases '1', ....'8' are for playing FROM a tableau onto any other pile (king or ace foundations)

        case '1':
            switch (destination)
            {
                //*playing onto king foundations
                case 'Q': *tL + tP[originInt]; break;
                case 'E': *tR + tP[originInt]; break;
                case 'A': *bL + tP[originInt]; break;
                case 'D': *bR + tP[originInt]; break;

                    //*playing onto ace foundation
                case 'S':
                    *aceF + tP[originInt];
                    lastWasKingPlay = false;
                    break;

                default: throw invalidCommand;
            }
            break;

        case '2':
            switch (destination)
            {
                //*playing onto king foundations
                case 'Q': *tL + tP[originInt]; break;
                case 'E': *tR + tP[originInt]; break;
                case 'A': *bL + tP[originInt]; break;
                case 'D': *bR + tP[originInt]; break;

                    //*playing onto ace foundation
                case 'S':
                    *aceF + tP[originInt];
                    lastWasKingPlay = false;
                    break;

                default: throw invalidCommand;
            }
            break;

        case '3':
            switch (destination)
            {
                //*playing onto king foundations
                case 'Q': *tL + tP[originInt]; break;
                case 'E': *tR + tP[originInt]; break;
                case 'A': *bL + tP[originInt]; break;
                case 'D': *bR + tP[originInt]; break;

                    //*playing onto ace foundation
                case 'S':
                    *aceF + tP[originInt];
                    lastWasKingPlay = false;
                    break;

                default: throw invalidCommand;
            }
            break;

        case '4':
            switch (destination)
            {
                //*playing onto king foundations
                case 'Q': *tL + tP[originInt]; break;
                case 'E': *tR + tP[originInt]; break;
                case 'A': *bL + tP[originInt]; break;
                case 'D': *bR + tP[originInt]; break;

                    //*playing onto ace foundation
                case 'S':
                    *aceF + tP[originInt];
                    lastWasKingPlay = false;
                    break;

                default: throw invalidCommand;
            }
            break;

        case '5':
            switch (destination)
            {
                //*playing onto king foundations
                case 'Q': *tL + tP[originInt]; break;
                case 'E': *tR + tP[originInt]; break;
                case 'A': *bL + tP[originInt]; break;
                case 'D': *bR + tP[originInt]; break;

                    //*playing onto ace foundation
                case 'S':
                    *aceF + tP[originInt];
                    lastWasKingPlay = false;
                    break;

                default: throw invalidCommand;
            }
            break;

        case '6':
            switch (destination)
            {
                //*playing onto king foundations
                case 'Q': *tL + tP[originInt]; break;
                case 'E': *tR + tP[originInt]; break;
                case 'A': *bL + tP[originInt]; break;
                case 'D': *bR + tP[originInt]; break;

                    //*playing onto ace foundation
                case 'S':
                    *aceF + tP[originInt];
                    lastWasKingPlay = false;
                    break;

                default: throw invalidCommand;
            }
            break;

        case '7':
            switch (destination)
            {
                //*playing onto king foundations
                case 'Q': *tL + tP[originInt]; break;
                case 'E': *tR + tP[originInt]; break;
                case 'A': *bL + tP[originInt]; break;
                case 'D': *bR + tP[originInt]; break;

                    //*playing onto ace foundation
                case 'S':
                    *aceF + tP[originInt];
                    lastWasKingPlay = false;
                    break;

                default: throw invalidCommand;
            }
            break;

        case '8':
            switch (destination)
            {
                //*playing onto king foundations
                case 'Q': *tL + tP[originInt]; break;
                case 'E': *tR + tP[originInt]; break;
                case 'A': *bL + tP[originInt]; break;
                case 'D': *bR + tP[originInt]; break;

                    //*playing onto ace foundation
                case 'S':
                    *aceF + tP[originInt];
                    lastWasKingPlay = false;
                    break;

                default: throw invalidCommand;
            }

            break;

            //*playing from king foundations (only acceptable move is to play onto ace foundation)
        case 'Q':
            switch (destination)
            {
                case 'S':

                    if (lastWasKingPlay && aceF->canReceive(tL->getCard()))
                        throw doubleKingPlay;

                    *aceF + tL;
                    break;

                default: throw kingF_Limitations;
            }
            lastWasKingPlay = true;
            break;

        case 'E':
            switch (destination)
            {
                case 'S':

                    if (lastWasKingPlay && aceF->canReceive(tR->getCard()))
                        throw doubleKingPlay;

                    *aceF + tR;
                    break;

                default: throw kingF_Limitations;

            }
            lastWasKingPlay = true;
            break;

        case 'A':
            switch (destination)
            {
                case 'S':

                    if (lastWasKingPlay && aceF->canReceive(bL->getCard()))
                        throw doubleKingPlay;

                    *aceF + bL;
                    break;

                default: throw kingF_Limitations;
            }
            lastWasKingPlay = true;
            break;

        case 'D':
            switch (destination)
            {
                case 'S':

                    if (lastWasKingPlay && aceF->canReceive(bR->getCard()))
                        throw doubleKingPlay;

                    *aceF + bR;
                    break;

                default: throw kingF_Limitations;
            }
            lastWasKingPlay = true;
            break;




        default: throw invalidCommand;
    }
}
void game::replenishSails()
{
    bool triedToReplenish = false;
    bool itWorked = !(w.isEmpty() && d.isEmptyStack());
    for (int i = 1; i < 9; i++)
    {
        if (tP[i]->isEmpty())
        {
            triedToReplenish = true;
            if (!w.isEmpty())
                *tP[i] + w;

            else if (!d.isEmptyStack())
                *tP[i] + d;
        }
    }
    if (triedToReplenish && itWorked)
        throw replenishTableaus;
}

std::string game::inGameHelp(std::string command)
{
    std::ostringstream out;

    out << "\n\n" + Y + "How to play:" + W + "\n\n"
        << "Simply press " + Y + "[Enter]" + W + " to draw from deck." << std::endl
        << "To play the card on top of the wastepile enter where you want to play it, use the " + Y + "tags" + W + " for reference." << std::endl
        << "To play between piles, enter the origin " + Y + "tag" + W + " followed by the destination " + Y + "tag" + W + " eg.(1s)" << std::endl
        << "If an input is invalid, don't worry, you will survive and I will let you know that is was an invalid command and nothing happened." << std::endl << std::endl
        << "Enlarge your terminal until you see both " + Y + "yellow" + W + " lines. The game happens between them." << std::endl
        << "Still kinda lost? Enter " + Y + "more help" + W + " or " + Y + "mh" + W + " for game rules." << std::endl
        << R << "\nPRO TIP:" << W << " Try to keep cards you'll soon need in the sails." << std::endl;

    if (command[0] == 'M')
        out << "\nCards(1 per draw) are drawn from deck onto the wastepile." << std::endl
        << "You can play FROM any pile " + R + "EXCEPT" + W + " from the " + M + "Ace Foundation" + W + ". Those only take cards in." << std::endl
        << "It is " + R + "ILLEGAL" + W + " to play twice FROM a " + G + "King Foundation" + W + " onto the " + M + "Ace Foundation" + W + " in a row." << std::endl
        << "Once the " + M + "Ace Foundation" + W + " receives a card from a " + G + "King Foundation" + W + ", the next card " + R + "MUST" + W + " come from elsewhere." << std::endl
        << "The " + Bu + "Tableaus/Sails" + W + ", are automatically refreshened from the waste or deck if you have cards available." << std::endl
        << "Empty piles are shown as a blank card representation." << std::endl << std::endl
        << "The goal of the game is to play all cards to the " + M + "Ace" + W + " and " + G + "King" + W + " Foundations." << std::endl << std::endl
        << "NOTE: \n" + M + "Ace Foundation builds UP in rank and loop back to Ace when a King is at the top.\n" + W
        << G + "King Foundations build DOWN in rank and become RETIRED when Ace is at the top. Meaning you cannot play ONTO it anymore. Playing FROM is still allowed." << std::endl
        << "Also, King Foundations cards can only be played onto the " + M + "Ace Foundation." + W << std::endl << std::endl
        << "If you play an illegal move, a " + R + "!!!WARNING!!!" + W + " will show you where you messed up." << std::endl
        << "That's it... Have fun!" << std::endl;

    return out.str();
}

void game::play()
{
    static bool lastWasKingPlay = false;

    replenishSails();

    std::string input;
    std::getline(std::cin, input);
    toUpper(input);


    //these will print how to play or game rules
    if (input == "HELP" || input == "H")
        throw inGameHelp("H");

    else if (input == "MORE HELP" || input == "MH")
        throw inGameHelp("MH");
    //early exit during game
    else if (input == "QUIT")
        throw input;




    if (input.empty())
    {
        draw();
        return;
    }

    //first if is for playing from wastepile
    //condition is that it is not empty and user entered a single letter/number (tag)
    if (input.size() == 1 && input[0] != 'H')
        if (!w.isEmpty())
            moveHandler(input[0], lastWasKingPlay);

        else//fail safe if wastepile is empty
        {
            if (TAGS.count(input))
                throw invalidCommand;

            if (w.isEmpty())
                throw std::invalid_argument("\n\n" + R + "!!!WARNING!!!" + W + " The wastepile is empty, hit " + Y + "[Enter]" + W + " to draw from deck.");
        }
    else if (input.size() == 2)
        moveHandler(input[0], input[1], lastWasKingPlay);

    else if (!input.empty())
        throw invalidCommand;


}

void game::draw()
{

    if (d.isEmptyStack())
        redeal();

    //!HOLD here when deck empty? like get deck empty so then redeal, or straight redeal if deck is empty?
    w.insert(d.pop());

}

void game::redeal()
{
    linkedListIterator<card> it = w.end();
    while (it != NULL)
    {
        d.push(*it);
        --it;
        --w;
    }
}



std::string game::printTable() //const
{

    //*SETUP FOR DECK:
    std::string dL = d.size() >= TEN ? std::to_string(d.size()) : "0" + std::to_string(d.size());//cards left in deck

    std::string bC = "░░░░░░░";
    if (!d.isEmptyStack())
        bC = d.top().getColor() ? colorfy(bC, "r") : colorfy(bC, "b");
    //bC = d.top().getColor() ? colorfy("░░░░░░░", "r") : colorfy("░░░░░░░", "b");

//!--------------------------------------------------------------------------------------------
//*SETUP FOR WASTE:
    std::string wL = w.length() >= TEN ? std::to_string(w.length()) : "0" + std::to_string(w.length());//cards left in wastepile

    printableCard wc;
    if (!w.isEmpty())
        wc.set(w);

    //!--------------------------------------------------------------------------------------------
    //*SETUP FOR ACE FOUNDATION:
    printableCard aF;
    aF.set(aceF);


    //!--------------------------------------------------------------------------------------------

    //*SETUP FOR KING FOUNDATIONS:

    //*TOP LEFT KF
    printableCard tl;//

    if (!tL->isEmpty())
        tl.set(tL);

    //*TOP RIGHT KF

    printableCard tr;
    if (!tR->isEmpty())
        tr.set(tR);

    //*BOTTOM LEFT KF
    printableCard bl;
    if (!bL->isEmpty())
        bl.set(bL);

    //*BOTTOM RIGHT KF
    printableCard br;
    if (!bR->isEmpty())
        br.set(bR);

    //!--------------------------------------------------------------------------------------------

    //*SETUP FOR TABLEAUS:

/*
                   [1]

            [tL]   [2]    [tR]

      [3]   [4]    [A]    [5]   [6]

           [bL]    [7]    [bR]

                   [8]
 */

 //*TABLEAU PILE #1
    printableCard tp1;
    if (!tP[1]->isEmpty())
        tp1.set(tP[1]);

    //*TABLEAU PILE #2
    printableCard tp2;
    if (!tP[2]->isEmpty())
        tp2.set(tP[2]);

    //*TABLEAU PILE #3
    printableCard tp3;
    if (!tP[3]->isEmpty())
        tp3.set(tP[3]);

    //*TABLEAU PILE #4
    printableCard tp4;
    if (!tP[4]->isEmpty())
        tp4.set(tP[4]);

    //*TABLEAU PILE #5
    printableCard tp5;
    if (!tP[5]->isEmpty())
        tp5.set(tP[5]);

    //*TABLEAU PILE #6
    printableCard tp6;
    if (!tP[6]->isEmpty())
        tp6.set(tP[6]);

    //*TABLEAU PILE #7
    printableCard tp7;
    if (!tP[7]->isEmpty())
        tp7.set(tP[7]);

    //*TABLEAU PILE #8
    printableCard tp8;
    if (!tP[8]->isEmpty())
        tp8.set(tP[8]);

    std::ostringstream allRows;

    //*tag variable names refer to the position of the card,
    //*t3 = third card counting from left to right, up to bottom

    std::string t1 = tag("1", "b");

    std::ostringstream _1stRow;
    _1stRow <<

        "\n\n         Deck: " << dL << "      Waste: " << wL << "\n"
        "        ┌─────────┐""" /* */    "   ┌─────────┐"              /*  */ "                    ┌─────────┐          \n"
        "        │ " << bC << " │" /* */ "   │ " << wc.t << "      │"  /*  */ "                    │ " << tp1.t << "      │    \n"
        "        │ " << bC << " │" /* */ "   │         │"              /*  */ "                    │         │   \n"
        "        │ " << bC << " │" /* */ "   │    " << wc.s << "    │" /*  */ "                    │    " << tp1.s << "    │     \n"
        "        │ " << bC << " │" /* */ "   │         │"              /*  */ "                    │         │   \n"
        "        │ " << bC << " │" /* */ "   │      " << wc.b << " │"  /*  */ "                    │" << t1 << "   " << tp1.b << " │   \n"
        "        └─────────┘""" /* */    "   └─────────┘"              /*  */ "                    └─────────┘   \n";


    std::string t2 = tag("Q", "g");
    std::string t3 = tag("2", "b");
    std::string t4 = tag("E", "g");
    std::string eB = tag("ENTER", "y");//enter button

    std::ostringstream _2ndRow;
    _2ndRow <<
        "         " << eB << "                       ┌─────────┐"                      /* */ "   ┌─────────┐"                       /* */ "   ┌─────────┐          \n"
        "                    "   "                   │ " << tl.t << "      │"          /* */ "   │ " << tp2.t << "      │"          /* */ "   │ " << tr.t << "      │    \n"
        "                    "   "                   │         │"                      /* */ "   │         │"                       /* */ "   │         │   \n"
        "                    "   "                   │    " << tl.s << "    │"         /* */ "   │    " << tp2.s << "    │"         /* */ "   │    " << tr.s << "    │     \n"
        "                    "   "                   │         │"                      /* */ "   │         │"                       /* */ "   │         │   \n"
        "                    "   "                   │" << t2 << "   " << tl.b << " │" /* */ "   │" << t3 << "   " << tp2.b << " │" /* */ "   │" << t4 << "   " << tr.b << " │   \n"
        "                    "   "                   └─────────┘"                      /* */ "   └─────────┘"                       /* */ "   └─────────┘   \n"; ;


    std::string t5 = tag("3", "b");
    std::string t6 = tag("4", "b");
    std::string t7 = tag("S", "m");
    std::string t8 = tag("5", "b");
    std::string t9 = tag("6", "b");

    std::ostringstream _3rdRow;
    _3rdRow <<
        "                         ┌─────────┐"                       /* */"   ┌─────────┐"                       /* */"   ┌─────────┐"                      /* */ "   ┌─────────┐"                       /* */ "   ┌─────────┐          \n"
        "                         │ " << tp3.t << "      │"          /* */"   │ " << tp4.t << "      │"          /* */"   │ " << aF.t << "      │"          /* */ "   │ " << tp5.t << "      │"          /* */ "   │ " << tp6.t << "      │    \n"
        "                         │         │"                       /* */"   │         │"                       /* */"   │         │"                      /* */ "   │         │"                       /* */ "   │         │   \n"
        "                         │    " << tp3.s << "    │"         /* */"   │    " << tp4.s << "    │"         /* */"   │    " << aF.s << "    │"         /* */ "   │    " << tp5.s << "    │"         /* */ "   │    " << tp6.s << "    │     \n"
        "                         │         │"                       /* */"   │         │"                       /* */"   │         │"                      /* */ "   │         │"                       /* */ "   │         │   \n"
        "                         │" << t5 << "   " << tp3.b << " │" /* */"   │" << t6 << "   " << tp4.b << " │" /* */"   │" << t7 << "   " << aF.b << " │" /* */ "   │" << t8 << "   " << tp5.b << " │" /* */ "   │" << t9 << "   " << tp6.b << " │   \n"
        "                         └─────────┘"                       /* */"   └─────────┘"                       /* */"   └─────────┘"                      /* */ "   └─────────┘"                       /* */ "   └─────────┘   \n";

    std::string t10 = tag("A", "g");
    std::string t11 = tag("7", "b");
    std::string t12 = tag("D", "g");

    std::ostringstream _4thRow;
    _4thRow <<
        "                                       ┌─────────┐"                      /* */ "   ┌─────────┐"                        /* */ "   ┌─────────┐          \n"
        "                                       │ " << bl.t << "      │"          /* */ "   │ " << tp7.t << "      │"           /* */ "   │ " << br.t << "      │    \n"
        "                                       │         │"                      /* */ "   │         │"                        /* */ "   │         │   \n"
        "                                       │    " << bl.s << "    │"         /* */ "   │    " << tp7.s << "    │"          /* */ "   │    " << br.s << "    │     \n"
        "                                       │         │"                      /* */ "   │         │"                        /* */ "   │         │   \n"
        "                                       │" << t10 << "   " << bl.b << " │"/* */ "   │" << t11 << "   " << tp7.b << " │" /* */ "   │" << t12 << "   " << br.b << " │   \n"
        "                                       └─────────┘"                      /* */ "   └─────────┘"                        /* */ "   └─────────┘   \n"; ;

    std::string t13 = tag("8", "b");

    std::ostringstream _5thRow;
    _5thRow <<
        "                                                     ┌─────────┐          \n"
        "                                                     │ " << tp8.t << "      │    \n"
        "                                                     │         │   \n"
        "                                                     │    " << tp8.s << "    │     \n"
        "                                                     │         │   \n"
        "                                                     │" << t13 << "   " << tp8.b << " │   \n"
        "                                                     └─────────┘   \n"

        << "\nLost? Enter " + Y + "help" + W + " or " + Y + "h" + W + " for... well... help!\n"
        "Enter " + R + "quit" + W + " to abandon this game and go back to the main menu." << std::endl;



    allRows
        << _1stRow.str()
        << _2ndRow.str()
        << _3rdRow.str()
        << _4thRow.str()
        << _5thRow.str();

    return allRows.str();

}

std::string tag(std::string tag, std::string color)
{
    std::string ret;
    if (color == "y")
        ret = Y + "[" + tag + "]" + W;
    if (color == "r")
        ret = R + "[" + tag + "]" + W;
    if (color == "b")
        ret = Bu + "[" + tag + "]" + W;
    if (color == "m")
        ret = M + "[" + tag + "]" + W;
    if (color == "c")
        ret = C + "[" + tag + "]" + W;
    if (color == "g")
        ret = G + "[" + tag + "]" + W;
    return ret;
}

std::string colorfy(std::string str, std::string color)
{
    std::string ret;
    if (color == "y")
        ret = Y + str + W;
    if (color == "r")
        ret = R + str + W;
    if (color == "b")
        ret = Bu + str + W;
    return ret;
}

void toUpper(std::string &x)
{
    for (char &c : x)
        c = toupper(c);
}
