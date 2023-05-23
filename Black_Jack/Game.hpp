#pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Cards.hpp"

class Game {
private:
    Player player;
    Player robot;
    bool m_running;
    bool m_GameOver;
    char m_command;

    void endGame();

public:
    Game(Cards& deck);
    void update();
    bool IsGameOver() const;
};

#endif // GAME_HPP
