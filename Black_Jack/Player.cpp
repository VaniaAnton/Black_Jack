#include "Player.hpp"
#include "Cards.hpp"

/*
Player class implementation:

The constructor initializes the player's name by reading it from the input, sets the initial hand value to 0, and saves the reference to the deck object.

The assignment operator (=) is overloaded to allow assigning one player object to another. It performs a member-wise assignment of the player's name, hand value, card, and deck.

The randomCard() function selects a random card from the deck, updates the player's hand by adding the points value of the card, and returns the points value.

The getHand() function returns the player's current hand value.

The getName() function returns the player's name.
*/
Player::Player(Cards& deck)
{
    std::cout << "Enter a name, then press the [Enter] key - ";
    std::getline(std::cin, this->m_name);
    std::cout << std::endl;

    this->m_hand = 0;
    this->m_deck = &deck; // Save the reference to the deck object
}

Player& Player::operator=(const Player& other)
{
    if (this != &other) {
        this->m_name = other.m_name;
        this->m_hand = other.m_hand;
        this->m_card = other.m_card; 
        this->m_deck = other.m_deck;
    }
    return *this;
}

int Player::randomCard()
{
    int num = rand() % 52;
    m_card = (*m_deck)[num]; // Assign the Card object to m_card

    m_hand += m_card.points; // Update m_hand using the points value

    return m_card.points; // Return the points value
}
int Player::getHand() const
{
    return m_hand;
}

std::string Player::getName() const
{
    return m_name;
}

