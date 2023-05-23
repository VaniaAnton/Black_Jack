#include <iostream>
#include <ctime>
#include "Cards.hpp"
#include "Player.hpp"
#include "Game.hpp"

int main()
{
    // Initialize random seed
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Create the deck of cards
    Cards deck;
    deck.addVector();

    // Create the game object with the deck
    Game game(deck);

    // Game loop
    while (!game.IsGameOver()) {
        game.update();
    }

    return 0;
}
