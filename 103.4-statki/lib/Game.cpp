//
// Created by michal on 06.12.23.
//

#include "Game.h"
#include <thread>
#include <chrono>
#include <iostream>
Game::Game(RandomPlayer p1, RandomPlayer p2, GameRules gameRules) : p1_(p1), p2_(p2), gameRules_(gameRules) {};

void Game::startGame() {
    int delay = 100;
    while(p1_.hasShips() && p2_.hasShips()) {
        p1_.shoot();
        p1_.maps_.first.show();
        std::cout<<"\n-----------------------------------------\n";
        p1_.maps_.second.showForEnemy();
        std::cout<<"\n-----------------------------------------\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        p2_.shoot();
        p2_.maps_.first.show();
        std::cout<<"\n-----------------------------------------\n";
        p2_.maps_.second.showForEnemy();
        std::cout<<"\n-----------------------------------------\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));

    }
}