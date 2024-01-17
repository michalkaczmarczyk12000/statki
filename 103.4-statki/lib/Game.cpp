//
// Created by michal on 06.12.23.
//

#include "Game.h"
#include <thread>
#include <chrono>
#include <iostream>
Game::Game(std::shared_ptr<Player> p1, std::shared_ptr<Player> p2, GameRules gameRules) : p1_(p1), p2_(p2), gameRules_(gameRules) {};

void Game::startGame() {
    //wymaga refactoringu ale do wersji 1 jest wystarczjące
    int delay = 10;
    std::cout << "Witaj w symulatorze wersja 1.1\n";
    while(true) {
        int delay = 10;
        if(isEnded(p1_, p2_)) {
            break;
        }
        turn(p1_, delay);
        if(isEnded(p2_, p1_)) {
            break;
        }
        turn(p2_,delay);
    }
}

void Game::turn(std::shared_ptr<Player> p, int delay) {
    p->shoot();
    std::cout << "Gracz" << p->getName() << "\n";
    p->getMyMap().show();
    std::cout<<"\n-----------------------------------------\n";
    p->getEnemyMap().showForEnemy();
    std::cout<<"\n-----------------------------------------\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
}

bool Game::isEnded(std::shared_ptr<Player> p, std::shared_ptr<Player> p2) {
    p->updateStatus();
    if (!p->hasShips()){
        std::cout<<"Wygrał Król niech żyje król " <<p2->getName() << "\n";
        return true;
    }
    return false;
}