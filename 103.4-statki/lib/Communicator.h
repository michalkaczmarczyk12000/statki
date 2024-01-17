#pragma once 
#include "Player.h"
#include "MapReader.h"
class Communicator {
private:
    std::shared_ptr<Player> p1_, p2_;
    MapReader mapReader;
public:
    Communicator();
    void playerTurnMsg();
};