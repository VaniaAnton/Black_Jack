#include "Game.hpp"
#include <iostream>
#include <thread>
#include <chrono>

// The Game class is responsible for managing the game flow and players.
// The constructor initializes the game by creating two players and setting the game state.
Game::Game(Cards& deck)
    : player1(deck), player2(deck)
{
    this->m_running = true;
    this->m_GameOver = false;
    this->m_command = ' ';
}

// Check the game result and display the winner
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
    // Print the sad emoji
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
// The update function starts the game by dealing initial cards and prompts the player to take their turn.
void Game::update()
{
    std::cout << "press ENTER to get two cards and start a game " <<'\n';
    player1.randomCard(); player1.randomCard();  player2.randomCard();  player2.randomCard();
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //std::cin.ignore();
    updatePlayer1();

}
// The updatePlayer1 function handles the player 1's turn by prompting them to draw a card or pass their turn.
void Game::updatePlayer1(){
    std::cout <<player1.getName()<<" now is your turn, if you want to get one more press W or,\npress S to pass the turn to the next player"<<'\n';
    std::cout << player1.getName() << " your Hand - " << player1.getHand() << '\n';
    std::cin >> this->m_command;
    
    switch (this->m_command) {
        case 'w':
        case 'W':
            std::cout << player1.getName() << ", you got - " << player1.randomCard()<< '\n';
            
            std::cout << std::endl;
            
            std::cout << player1.getName() << " your Hand - " << player1.getHand() << '\n';
            
            std::cout<<std::endl;
            std::cout<<std::endl;
            std::cout << "press ENTER to continue a game " <<'\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.ignore();
            for (int i=0; i<15; i++) {
                std::cout<<std::endl;
            }
            // Delay for 5 seconds
                std::this_thread::sleep_for(std::chrono::seconds(5));
            updatePlayer2();
            break;
        case 's':
        case 'S':
            //for mac OS use this to skip line in console
            for (int i=0; i<15; i++) {
                std::cout<<std::endl;
            }
            //for Windows u can comment code before and write #include <cstdlib>  or #include <stdlib.h> and use
            //system("cls")
            
            // Delay for 5 seconds
                std::this_thread::sleep_for(std::chrono::seconds(5));
            updatePlayer2();
            break;
        default:
            std::cout<<std::endl;
            std::cout<<std::endl;
            std::cout<<"Incorrect key, please try again"<<'\n';
            updatePlayer1();
    }
}
// The updatePlayer2 function handles the player 2's turn by prompting them to draw a card, pass their turn, or check the results.
void Game::updatePlayer2(){
    std::cout <<player2.getName()<<" now is your turn, if you want to get one more press W or,\npress S to pass the turn to the next player \npress Q if you have enough cards and we can check cards"<<'\n';
    std::cout << player2.getName() << " your Hand - " << player2.getHand() << '\n';
    std::cin >> this->m_command;
    
    switch (this->m_command) {
        case 'w':
        case 'W':
            std::cout << player2.getName() << ", you got - " << player2.randomCard()<< '\n';
            
            std::cout << std::endl;
            
            std::cout << player2.getName() << " your Hand - " << player2.getHand() << '\n';
            
            std::cout<<std::endl;
            std::cout<<std::endl;
            std::cout << "press ENTER to continue a game " <<'\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.ignore();
            for (int i=0; i<15; i++) {
                std::cout<<std::endl;
            }
            // Delay for 5 seconds
                std::this_thread::sleep_for(std::chrono::seconds(5));
            updatePlayer1();
            break;
        case 's':
        case 'S':
            //for mac OS use this to skip line in console
            for (int i=0; i<15; i++) {
                std::cout<<std::endl;
            }
            //for Windows u can comment code before and write #include <cstdlib>  or #include <stdlib.h> and use
            //system("cls")
            
            // Delay for 5 seconds
                std::this_thread::sleep_for(std::chrono::seconds(5));
            updatePlayer1();
            break;
        case 'q':
        case 'Q':
            for (int i=0; i<15; i++) {
                std::cout<<std::endl;
            }
            endGame();
            break;
        default:
            std::cout<<std::endl;
            std::cout<<std::endl;
            std::cout<<"Incorrect key, please try again"<<'\n';
            updatePlayer2();
    }
}

// The IsGameOver function checks if the game is over.
bool Game::IsGameOver() const { return m_GameOver; }

