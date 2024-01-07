//
// Created by michal on 06.12.23.
//

#include "Game.h"
#include <thread>
#include <chrono>
Game::Game(Player p1, Player p2, GameRules gameRules) : p1_(p1), p2_(p2), gameRules_(gameRules) {};

void Game::startGame() {
    while(p1_.hasShips() && p2_.hasShips()) {
        p1_.shoot();
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        p2_.shoot();
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    }
}