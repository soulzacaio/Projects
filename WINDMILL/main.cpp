/*
 Program name: main.cpp
 Author: Caio Souza
 Date last updated: 12/05/2023
 Purpose: Final Project Windmill
*/

#include "pile.h"
#include "aceFoundation.h"
#include "wastepile.h"
#include "game.h"
#include "deck.h"
#include <iostream>
#include <sstream>
#include <limits>
#include <iomanip>

void resetStream();
void mainMenu();
int validChoice();
int main()
{
    std::string playAgain = "Y";

    while (playAgain[0] == 'Y')
    {
        bool abandonedGame = false;
        mainMenu();

        game g;
        std::cout << g << std::endl;

        while (!g.gameWon())
        {
            try
            {
                std::cout << Y << std::setw(120) << std::setfill('-') << W << std::endl;
                std::cout << "\nYour turn:" << std::endl; //$
                g.play();
            }
            catch (const std::exception &e)
            {
                std::cerr << "\n\n" + R + "!!!WARNING!!! " + W << e.what() << '\n';
            }
            catch (std::string strThrow) // catch for in game help and early quit
            {
                if (strThrow == "QUIT")
                {
                    abandonedGame = true;
                    std::cout << R << "Quiting this game now." << W << std::endl;
                    break;
                }
                std::cout << "\n\n" + strThrow << std::endl;
            }

            std::cout << g << std::endl;

            if (g.gameWon())
                std::cout << R + "Ooooof, clean victory. Congrats!!!" + W << std::endl;
        }
        if (!abandonedGame)
        {
            std::cout << "Great play, wanna go again?! (y/n)" << std::endl;
            std::getline(std::cin, playAgain);
            toUpper(playAgain);
        }
    }

    std::cout << "See ya later o/" << std::endl;

    return 0;
}


void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int validChoice()
{
    std::cout << "\nPick an option?";
    int choice;
    std::cin >> choice;

    while (!std::cin || choice < 1 || choice > 5)
    {
        if (!std::cin)
        {
            std::cout << "Invalid entry.\n";
            resetStream();
        }
        else
            std::cout << "Chose from the menu options, pick any number you see in the list.\n";

        std::cout << "\nPick an option?";
        std::cin >> choice;
    }
    return choice;
}

void mainMenu()
{

    std::cout << std::setfill('=') << std::setw(90) << " " << std::endl;
    std::cout << std::setfill(' ') << std::setw(55) << "Welcome to Windmill!" << std::endl;
    std::cout << std::setfill('=') << std::setw(90) << " " << std::endl;


    std::string menu = "1 - Let's play!!!\n"
        "2 - Choose this if you are like: Windwhat?\n"
        "3 - How to play it?\n"
        "4 - About this project.\n"
        "5 - Quit.\n";

    std::cout << menu << std::endl;
    int choice = validChoice();

    while (choice > 1 && choice <= 5)
    {
        switch (choice)
        {
            case 2:
                std::cout << Y << game::read("windmill") << W << std::endl;
                break;
            case 3:
                std::cout << Y << game::read("instructions") << W << std::endl;
                break;
            case 4:
                std::cout << Y << game::read("about") << W << std::endl;
                break;
            case 5:
                std::cout << R << "Quitting now" << W;
                exit(1);
        }

        std::cout << menu << std::endl;
        choice = validChoice();
    }
    resetStream(); // this clears anything resting in std::cin, it was causing problems internally
}
