//
// Created by michal on 06.12.23.
//

#ifndef INC_103_4_STATKI_RANDOMPLAYER_H
#define INC_103_4_STATKI_RANDOMPLAYER_H
#include "Player.h"
#include <chrono>
#include <random>
#include <algorithm>



class RandomPlayer : public Player{
public:
    RandomPlayer(std::string name, std::pair<Map, Map> map, std::vector<Ship> ships ,int rank=1000);
    void shoot();
private:
    std::vector<std::pair<int, int>> possibleShoots_;
    void randomSelectTarget();
    std::pair<int, int> getRandomField();
    std::mt19937 gen;

};


#endif //INC_103_4_STATKI_RANDOMPLAYER_H
