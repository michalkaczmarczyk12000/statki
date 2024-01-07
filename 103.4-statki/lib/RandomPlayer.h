//
// Created by michal on 06.12.23.
//

#ifndef INC_103_4_STATKI_RANDOMPLAYER_H
#define INC_103_4_STATKI_RANDOMPLAYER_H
#include "Player.h"


class RandomPlayer : public Player{
public:
    RandomPlayer(std::string name, Map map);
    RandomPlayer(std::string name, int rank, Map map);
private:
    std::vector<Field> possibleShoots;
};


#endif //INC_103_4_STATKI_RANDOMPLAYER_H
