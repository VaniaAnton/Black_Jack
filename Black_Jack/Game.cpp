#include "Game.hpp"
#include <iostream>

Game::Game(Cards& deck)
    : player1(deck), player2(deck)
{
    this->m_running = true;
    this->m_GameOver = false;
    this->m_command = ' ';
}

void Game::endGame()
{
    if (player1.getHand() == 21 && player1.getHand() > player2.getHand()) {
        this->m_GameOver = true;
        std::cout << player1.getName()<< " win!\n";
        std::cout <<player2.getName()<< " lose!\n";
    }
    else if (player2.getHand() > 21 && player2.getHand() <= 21 ) {
        this->m_GameOver = true;
        std::cout << player1.getName()<< " win!\n";
        std::cout <<player2.getName()<< " lose!\n";
        
    }
    
    else if (player2.getHand() == 21 && player2.getHand() > player1.getHand()) {
        this->m_GameOver = true;
        std::cout <<player2.getName()<< " win!\n";
        std::cout << player1.getName()<< " lose!\n";
    }
    else if ( player1.getHand() > 21 && player2.getHand() <=21) {
        this->m_GameOver = true;
        std::cout <<player2.getName()<< " win!\n";
        std::cout << player1.getName()<< " lose!\n";
    }
    else if (player1.getHand() >21 && player2.getHand()>21){
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
    std::cout << "Enter W to draw a card for both \nEnter A to draw a card for " <<player1.getName()<< "\nEnter D to draw a card for "<<player2.getName()<<"\nThe first person who is closer to 21 wins!\n";
    std::cin >> this->m_command;

    switch (this->m_command) {
        case 'w':
        case 'W':
            std::cout << player1.getName() << " Drew - " << player1.randomCard() << '\n';
            std::cout << player2.getName() << " Drew - " << player2.randomCard() << '\n';

            std::cout << std::endl;
            std::cout << std::endl;

            std::cout << player1.getName() << "'s Hand - " << player1.getHand() << '\n';
            std::cout << player2.getName() << "'s Hand - " << player2.getHand() << '\n';

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
            std::cout << player1.getName() << " Drew - " << player1.randomCard() << '\n';
            std::cout << player2.getName() << "  did not Draw a card "<<std::endl;

            std::cout << std::endl;
            std::cout << std::endl;

            std::cout << player1.getName() << "'s Hand - " << player1.getHand() << '\n';
            std::cout << player2.getName() << "'s Hand - " << player2.getHand() << '\n';

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
            std::cout << player1.getName() << " did not Draw a card" << '\n';
            std::cout << player2.getName() << "  Drew -  "<<player2.randomCard()<<std::endl;

            std::cout << std::endl;
            std::cout << std::endl;

            std::cout << player1.getName() << "'s Hand - " << player1.getHand() << '\n';
            std::cout << player2.getName() << "'s Hand - " << player2.getHand() << '\n';

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
void Game::updatePlayer1(){
    std::cout << player1.getName()<< " Now is your turn, press W to draw a card " <<'\n';
    std::cin >> this->m_command;
    
    switch (this->m_command) {
        case 'w':
        case 'W':
            std::cout << player1.getName() << ", you got - " << player1.randomCard()<< '\n';
            
            std::cout << std::endl;
            
            std::cout << player1.getName() << " your Hand - " << player1.getHand() << '\n';
            
            std::cout <<"If you want to get one more press W , else press S to pass the turn to the next player "<<'\n';
            
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.ignore();
        case 's':
        case 'S':
            for (int i=0; i<10; i++) {
                std::cout<<std::endl;
            }
            updatePlayer2();
            break;
    }
}
void Game::updatePlayer2(){
    std::cout << player2.getName()<< " Now is your turn, press W to draw a card " <<'\n';
    std::cin >> this->m_command;
    
    switch (this->m_command) {
        case 'w':
        case 'W':
            std::cout << player2.getName() << ", you got - " << player2.randomCard()<< '\n';
            
            std::cout << std::endl;
            
            std::cout << player2.getName() << " your Hand - " << player2.getHand() << '\n';
            
            std::cout <<"If you want to get one more press W , else press S to check who is winner "<<'\n';
            
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.ignore();
        case 's':
        case 'S':
            endGame();
            break;
    }
}


bool Game::IsGameOver() const { return m_GameOver; }

