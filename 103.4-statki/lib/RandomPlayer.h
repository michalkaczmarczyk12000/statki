//
// Created by michal on 06.12.23.
//

#ifndef INC_103_4_STATKI_RANDOMPLAYER_H
#define INC_103_4_STATKI_RANDOMPLAYER_H
#include "Player.h"
#include <chrono>
#include <random>
#include <algorithm>



class RandomPlayer : public Player {
public:
    RandomPlayer(std::string name, maps playerMaps, int rank=1000);
    virtual Coordinates shoot() override;
    void turn() override;
    virtual ~RandomPlayer();
protected:
    Coordinates randomSelectTarget();
    Coordinates getRandomField();
    std::mt19937 gen;
};


#endif //INC_103_4_STATKI_RANDOMPLAYER_H
