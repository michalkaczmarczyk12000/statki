//
// Created by michal on 06.12.23.
//

#include "Game.h"
#include <thread>
#include <chrono>
#include <iostream>
Game::Game(std::shared_ptr<Player> p1, std::shared_ptr<Player> p2, Communicator com) : p1_(p1), p2_(p2), com_(com) {};

void Game::startGame() {
    com_.welcomeMsg();
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
    com_.turnMsg(p);
    com_.showMaps(p);
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
}

bool Game::isEnded(std::shared_ptr<Player> p, std::shared_ptr<Player> p2) {
    p->updateStatus();
    if (!p->hasShips()){
        com_.winMsg(p2);
        return true;
    }
    return false;
}

void Game::prepGame() {
    com_.welcomeMsg();
    std::cout << "Podaj imiona 2 graczy" << std::endl;
    std::string name1, name2;
    std::cin >> name1 >> name2;
    std::cout << "Podaj sciezke do mapy pierwszego gracza" << std::endl;
    
}