
#ifndef CARDS_HPP
#define CARDS_HPP

#include <iostream>
#include <vector>
#include <string>

// Structure to represent a card with rank, suit, and points.
struct Card {
std::string rank; // Rank of the card (e.g., "Ace", "2", "3", ..., "King").
std::string suit; // Suit of the card (e.g., "Spades", "Hearts", "Diamonds", "Clubs").
int points; // Points associated with the card.
};

class Cards {
private:
    std::vector<Card> cards; // Vector to store all the cards.
    std::vector<std::string>All_Suits; // Vector to store all possible suits.
    
public:
    Cards(); // Constructor to initialize the cards and suits.
    void addCard(const std::string& name, const std::string& suit, int points); // Add a card to the deck.
    void printAllCards() const; // Print all the cards in the deck.
    void addVector(); // Add a vector of cards to the deck.
    
    Card& operator[](int index);             // Overloaded operator to access a card by index.
    
    friend std::ostream& operator<<(std::ostream& os, const Cards& cards);    // Overloaded operator to output the deck.
    friend std::istream& operator>>(std::istream& is, Cards& cards);          // Overloaded operator to input the deck.
};
#endif // CARDS_HPP
