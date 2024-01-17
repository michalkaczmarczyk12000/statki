//
// Created by michal on 06.12.23.
//

#include "Game.h"
#include <thread>
#include <chrono>
#include <iostream>
Game::Game(Communicator com, std::shared_ptr<Player> p1, std::shared_ptr<Player> p2) : p1_(p1), p2_(p2), com_(com) {};

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
    std::string filename1, filename2;
    std::cout << "Podaj sciezke do mapy pierwszego gracza" << std::endl;
    std::cin >> filename1;
    std::cout << "Podaj sciezke do mapy drugiego gracza" << std::endl;
    std::cin >> filename2;
    MapReader mr;
    Map map1 = mr.createMap(filename1);
    Map map2 = mr.createMap(filename2);
    maps maps1 = {
        std::make_pair(std::make_shared<Map>(map1), std::make_shared<Map>(map2))};

    maps maps2 = {
        std::make_pair(std::make_shared<Map>(map2), std::make_shared<Map>(map1))};
    while(true) {
        std::cout << "Czy gracz pierwszy ma być człowiekiem(1), losowym graczem(2), czy graczem AI(3)? Wpisz odpowiednia cyfre:" << std::endl;
        int decision;
        std::cin >> decision;
        if(decision == 1) {
            HumanPlayer p1(name1, maps1);
            p1_ = std::make_shared<HumanPlayer>(p1);
            break;
        }
        else if(decision == 2) {
            RandomPlayer p1(name1, maps1);
            p1_ = std::make_shared<RandomPlayer>(p1);
            break;
        }
        else if(decision == 3) {
            AdvancedAIPlayer p1(name1, maps1);
            p1_ = std::make_shared<AdvancedAIPlayer>(p1);
            break;
        }
        std::cout << "Nieprawidłowy wybór" << std::endl;
    }
    while(true) {
        std::cout << "Czy gracz drugi ma być człowiekiem(1), losowym graczem(2), czy graczem AI(3)? Wpisz odpowiednia cyfre:" << std::endl;
        int decision;
        std::cin >> decision;
        if(decision == 1) {
            HumanPlayer p2(name1, maps2);
            p2_ = std::make_shared<HumanPlayer>(p2);
            break;
        }
        else if(decision == 2) {
            RandomPlayer p2(name1, maps2);
            p2_ = std::make_shared<RandomPlayer>(p2);
            break;
        }
        else if(decision == 3) {
            AdvancedAIPlayer p2(name1, maps2);
            p2_ = std::make_shared<AdvancedAIPlayer>(p2);
            break;
        }
        std::cout << "Nieprawidłowy wybór" << std::endl;
    }
    

    
    
}
