//
// Created by michal on 16.01.24.
//

#ifndef STATKI_PLAYERAI_H
#define STATKI_PLAYERAI_H
#include "Player.h"

class PlayerAI : public Player {
public:
    PlayerAI(std::string name, maps playerMaps, int rank = 1000);
    virtual ~PlayerAI();
};


#endif //STATKI_PLAYERAI_H
