//
// Created by michal on 06.12.23.
//

#include "Game.h"
#include <thread>
#include <chrono>
#include <iostream>
Game::Game(RandomPlayer p1, RandomPlayer p2, GameRules gameRules) : p1_(p1), p2_(p2), gameRules_(gameRules) {};

void Game::startGame() {
    int delay = 10;
    std::cout << "Witaj w symulatorze wersja 1.1\n";
    while(true) {
        p1_.updateShips();
        if (!p1_.hasShips()){
            std::cout<<"Wygrał Król niech żyje król 2\n";
            break;
        }
        p1_.shoot();
        std::cout << "Gracz pierwszy\n";
        p1_.maps_.first.show();
        std::cout<<"\n-----------------------------------------\n";
        p1_.maps_.second.showForEnemy();
        std::cout<<"\n-----------------------------------------\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        p2_.updateShips();
        if (!p2_.hasShips()){
            std::cout<<"Wygrał Król niech żyje król 1\n";
            break;
        }
        p2_.shoot();
        std::cout << "Gracz drugi\n";
        p2_.maps_.first.show();
        std::cout<<"\n-----------------------------------------\n";
        p2_.maps_.second.showForEnemy();
        std::cout<<"\n-----------------------------------------\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}