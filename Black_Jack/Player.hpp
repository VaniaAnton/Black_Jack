#pragma once
/*
 The Player class handles the player's hand and name  returns value  used by the game class
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "Cards.hpp"
#include <string>
#include <ctime>
#include <limits>
#include <algorithm>

class Player {
private:
std::string m_name; // Player's name
int m_hand; // Player's hand (total points)
Card m_card; // Current card drawn by the player
Cards* m_deck; // Pointer to the Cards object (deck of cards)

public:
    Player(Cards& deck); // Constructor
    Player& operator=(const Player& other); // Assignment operatorv

    int randomCard();   // Draw a random card from the deck and update the player's hand
    int getHand() const;   // Get the player's hand (total points)
    std::string getName() const;   // Get the player's name

};

#endif // PLAYER_HPP
