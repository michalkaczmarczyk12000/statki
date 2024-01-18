//
// Created by michal on 06.12.23.
//

#include "Game.h"
#include <thread>
#include <chrono>
#include <iostream>
Game::Game(Communicator& com, std::shared_ptr<Player> p1, std::shared_ptr<Player> p2) : p1_(p1), p2_(p2), com_(com) {};

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
    com_.turnMsg(p);
    p->turn();
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
    std::string name1, name2;
    com_.loadNames(name1, name2);
    std::string filename1, filename2;
    com_.loadFilenames(filename1, filename2);
    MapReader mr;
    Map map1 = mr.createMap(filename1);
    Map map2 = mr.createMap(filename2);
    maps maps1 = {
        std::make_pair(std::make_shared<Map>(map1), std::make_shared<Map>(map2))};

    maps maps2 = {
        std::make_pair(std::make_shared<Map>(map2), std::make_shared<Map>(map1))};
    com_.selectPlayers(p1_, maps1, name1);
    com_.selectPlayers(p2_, maps2, name2); 
}
