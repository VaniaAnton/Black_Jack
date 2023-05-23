#include "Game.hpp"
#include <iostream>

Game::Game(Cards& deck)
    : player(deck), robot(deck)
{
    this->m_running = true;
    this->m_GameOver = false;
    this->m_command = ' ';
}

void Game::endGame()
{
    if (player.getHand() == 21 && player.getHand() > robot.getHand()) {
        this->m_GameOver = true;
        std::cout << player.getName()<< " win!\n";
        std::cout <<robot.getName()<< " lose!\n";
    }
    else if (robot.getHand() > 21 && player.getHand() <= 21 ) {
        this->m_GameOver = true;
        std::cout << player.getName()<< " win!\n";
        std::cout <<robot.getName()<< " lose!\n";
        
    }
    
    else if (robot.getHand() == 21 && robot.getHand() > player.getHand()) {
        this->m_GameOver = true;
        std::cout <<robot.getName()<< " win!\n";
        std::cout << player.getName()<< " lose!\n";
    }
    else if ( player.getHand() > 21 && robot.getHand() <=21) {
        this->m_GameOver = true;
        std::cout <<robot.getName()<< " win!\n";
        std::cout << player.getName()<< " lose!\n";
    }
    else if (player.getHand() >21 && robot.getHand()>21){
        std::cout<<"       BOTH ARE LOSERS"<<std::endl;
        std::cout << "       a$$$$$$$$$$a" << std::endl;
        std::cout  << "     a$$$$$$$$$$$$$$a" << std::endl;
        std::cout  << "   a$$$$$$$$$$$$$$$$$$a" << std::endl;
        std::cout  << "  a$$$$$$$$$$$$$$$$$$$$a" << std::endl;
        std::cout  << " a$$$$$   $$$$$$   $$$$$a" << std::endl;
        std::cout  << "a$$$$$     $$$$     $$$$$a" << std::endl;
        std::cout  << "a$$$$$$$ $$$$$$$$$$$$$$$$a" << std::endl;
        std::cout  << "a$$$$$$$ $$$$$$$$$$$$$$$$a" << std::endl;
        std::cout  << "a$$$$$$$$$$$$$$$$$$$$$$$$a" << std::endl;
        std::cout  << " a$$$$$$          $$$$$$a" << std::endl;
        std::cout  << "  a$$$$  $$$$$$$$  $$$$a" << std::endl;
        std::cout  << "   a$$ $$$$$$$$$$$$ $$a" << std::endl;
        std::cout  << "     a$$$$$$$$$$$$$$a" << std::endl;
        std::cout  << "       a$$$$$$$$$$a" << std::endl;
        this->m_GameOver = true;
    }
        
    else {
        std::cout << "We continue the game until someone wins\n";
    }
}

void Game::update()
{
    std::cout << "Enter W to draw a card for both \nEnter A to draw a card for " <<player.getName()<< "\nEnter D to draw a card for "<<robot.getName()<<"\nThe first person who is closer to 21 wins!\n";
    std::cin >> this->m_command;

    switch (this->m_command) {
        case 'w':
        case 'W':
            std::cout << player.getName() << " Drew - " << player.randomCard() << '\n';
            std::cout << robot.getName() << " Drew - " << robot.randomCard() << '\n';

            std::cout << std::endl;
            std::cout << std::endl;

            std::cout << player.getName() << "'s Hand - " << player.getHand() << '\n';
            std::cout << robot.getName() << "'s Hand - " << robot.getHand() << '\n';

            std::cout << std::endl;
            std::cout << std::endl;

            endGame();

            std::cout << "Press [Enter] to continue...\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.ignore();
            break;
        case 'a':
        case 'A':
            std::cout << player.getName() << " Drew - " << player.randomCard() << '\n';
            std::cout << robot.getName() << "  did not Draw a card "<<std::endl;

            std::cout << std::endl;
            std::cout << std::endl;

            std::cout << player.getName() << "'s Hand - " << player.getHand() << '\n';
            std::cout << robot.getName() << "'s Hand - " << robot.getHand() << '\n';

            std::cout << std::endl;
            std::cout << std::endl;

            endGame();

            std::cout << "Press [Enter] to continue...\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.ignore();
            break;
        case 'd':
        case 'D':
            std::cout << player.getName() << " did not Draw a card" << '\n';
            std::cout << robot.getName() << "  Drew -  "<<robot.randomCard()<<std::endl;

            std::cout << std::endl;
            std::cout << std::endl;

            std::cout << player.getName() << "'s Hand - " << player.getHand() << '\n';
            std::cout << robot.getName() << "'s Hand - " << robot.getHand() << '\n';

            std::cout << std::endl;
            std::cout << std::endl;

            endGame();

            std::cout << "Press [Enter] to continue...\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.ignore();
            break;
        default:
            std::cout << "Not a valid command, please try again.\nPress [Enter] to continue...\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.ignore();
            // for clearing console (works only on Windows)
            // system("cls")
            break;
    }
}

bool Game::IsGameOver() const { return m_GameOver; }

