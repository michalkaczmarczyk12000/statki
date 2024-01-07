//
// Created by michal on 06.12.23.
//

#ifndef INC_103_4_STATKI_RANDOMPLAYER_H
#define INC_103_4_STATKI_RANDOMPLAYER_H
#include "Player.h"


class RandomPlayer : public Player{
public:
    RandomPlayer(std::string name, Map map, int rank=1000);
private:
    std::vector<std::pair<int, int>> possibleShoots;
    void randomSelectTarget();
    std::pair<int, int> getRandom() const;


};


#endif //INC_103_4_STATKI_RANDOMPLAYER_H
