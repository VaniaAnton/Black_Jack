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
    std::string m_name;
    int m_hand;
    Card m_card;
    Cards* m_deck; // Pointer to Cards object

public:
    Player(Cards& deck);
    Player& operator=(const Player& other); // Assignment operator

    int randomCard();
    int getHand() const; // Function to get the player's hand
    std::string getName() const; // Function to get the player's name
};

#endif // PLAYER_HPP
