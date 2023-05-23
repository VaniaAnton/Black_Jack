#pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Cards.hpp"

class Game {
private:
    Player player1;
    Player player2;
    bool m_running;
    bool m_GameOver;
    char m_command;

    void endGame();

public:
    Game(Cards& deck);
    void update();
    void updatePlayer1();
    void updatePlayer2();
    bool IsGameOver() const;
};

#endif // GAME_HPP
