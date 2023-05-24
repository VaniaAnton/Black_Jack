#include "Cards.hpp"

Cards::Cards()
{
All_Suits = { "Hearts", "Diamonds", "Clubs", "Spades" }; // Initialize the vector of all suits.
addVector(); // Add all the cards to the deck.
}

void Cards::addCard(const std::string& name, const std::string& suit, int points)
{
    Card card;
    card.rank = name;
    card.suit = suit;
    card.points = points;

    cards.push_back(card); // Add the card to the deck.
}

void Cards::printAllCards() const
{
    for (const Card& card : cards) {
        std::cout << card.rank << " of " << card.suit << " - " << card.points << " points\n";
    }
}

void Cards::addVector()
{
    // Add the face cards (King, Queen, Jack, Ace) for each suit.
    for (const std::string& suit : All_Suits) {
        addCard("King", suit, 10);
        addCard("Queen", suit, 10);
        addCard("Jack", suit, 10);
        addCard("Ace", suit, 11);
    }
    // Add the number cards (2-10) for each suit.
    for (const std::string& suit : All_Suits){
        for (int i = 2; i<=10; i++) {
            addCard(std::to_string(i), suit, i);
        }
    }
}

Card& Cards::operator[](int index)
{
    return cards[index];
}

std::ostream& operator<<(std::ostream& os, const Cards& cards)
{
    for (const Card& card : cards.cards) {
        os << card.rank << " of " << card.suit << " - " << card.points << " points\n";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Cards& cards)
{
    std::string rank, suit;
    int points;
    is >> rank >> suit >> points;
    cards.addCard(rank, suit, points);
    return is;
}

