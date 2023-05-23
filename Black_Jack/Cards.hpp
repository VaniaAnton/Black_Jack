#ifndef CARDS_HPP
#define CARDS_HPP

#include <iostream>
#include <vector>
#include <string>

struct Card {
    std::string rank;
    std::string suit;
    int points;
};

class Cards {
private:
    std::vector<Card> cards;
    std::vector<std::string> All_Suits;

public:
    Cards();
    void addCard(const std::string& name, const std::string& suit, int points);
    void printAllCards() const;
    void addVector();

    Card& operator[](int index);

    friend std::ostream& operator<<(std::ostream& os, const Cards& cards);
    friend std::istream& operator>>(std::istream& is, Cards& cards);
};

#endif // CARDS_HPP
