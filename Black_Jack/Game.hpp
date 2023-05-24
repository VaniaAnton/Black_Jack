#pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Cards.hpp"

class Game {
private:
Player player1; // Player 1
Player player2; // Player 2
bool m_running; // Game running flag
bool m_GameOver; // Game over flag
char m_command; // User input command
  
    void endGame();  // Function to determine if the game is over

public:
Game(Cards& deck); // Constructor with deck parameter
void update(); // Main game update function
void updatePlayer1(); // Update function for Player 1
void updatePlayer2(); // Update function for Player 2
bool IsGameOver() const; // Function to check if the game is over
};

#endif // GAME_HPP

