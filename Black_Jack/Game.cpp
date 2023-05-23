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
    else if (player1.getHand()>player2.getHand() && player1.getHand() <= 21){
        this->m_GameOver = true;
        std::cout << player1.getName()<< " win!\n";
        std::cout <<player2.getName()<< " lose!\n";
    }
    else if (player2.getHand()>player1.getHand() && player2.getHand() <= 21){
        this->m_GameOver = true;
        std::cout << player2.getName()<< " win!\n";
        std::cout <<player1.getName()<< " lose!\n";
    }
        
}

void Game::update()
{
    std::cout << "press ENTER to get two cards and start a game " <<'\n';
    player1.randomCard(); player1.randomCard();  player2.randomCard();  player2.randomCard();
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //std::cin.ignore();
    updatePlayer1();

}
void Game::updatePlayer1(){
    std::cout <<player1.getName()<<" now is your turn, if you want to get one more press W ,\npress S to pass the turn to the next player \npress Q if you have enough cards and will not take more"<<'\n';
    std::cout << player1.getName() << " your Hand - " << player1.getHand() << '\n';
    std::cin >> this->m_command;
    
    switch (this->m_command) {
        case 'w':
        case 'W':
            std::cout << player1.getName() << ", you got - " << player1.randomCard()<< '\n';
            
            std::cout << std::endl;
            
            std::cout << player1.getName() << " your Hand - " << player1.getHand() << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.ignore();
            updatePlayer2();
            break;
        case 's':
        case 'S':
            for (int i=0; i<10; i++) {
                std::cout<<std::endl;
            }
            updatePlayer2();
            break;
        case 'q':
        case 'Q':
            updatePlayer2();
            break;
    }
}
void Game::updatePlayer2(){
    std::cout <<player2.getName()<<" now is your turn, if you want to get one more press W ,\npress S to pass the turn to the next player \npress Q if you have enough cards and will not take more"<<'\n';
    std::cout << player2.getName() << " your Hand - " << player2.getHand() << '\n';
    std::cin >> this->m_command;
    
    switch (this->m_command) {
        case 'w':
        case 'W':
            std::cout << player2.getName() << ", you got - " << player2.randomCard()<< '\n';
            
            std::cout << std::endl;
            
            std::cout << player2.getName() << " your Hand - " << player2.getHand() << '\n';
            
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.ignore();
            updatePlayer1();
            break;
        case 's':
        case 'S':
            for (int i=0; i<10; i++) {
                std::cout<<std::endl;
            }
            updatePlayer1();
            break;
        case 'q':
        case 'Q':
            endGame();
            break;
    }
}


bool Game::IsGameOver() const { return m_GameOver; }

