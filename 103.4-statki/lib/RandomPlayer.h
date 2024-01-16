//
// Created by michal on 06.12.23.
//

#ifndef INC_103_4_STATKI_RANDOMPLAYER_H
#define INC_103_4_STATKI_RANDOMPLAYER_H
#include "PlayerAI.h"
#include <chrono>
#include <random>
#include <algorithm>



class RandomPlayer : public PlayerAI {
public:
    RandomPlayer(std::string name, maps playerMaps, int rank=1000);
    void shoot() override;
private:
    std::vector<std::pair<int, int>> possibleShoots_;
    void randomSelectTarget();
    std::pair<int, int> getRandomField();
    std::mt19937 gen;
};


#endif //INC_103_4_STATKI_RANDOMPLAYER_H
