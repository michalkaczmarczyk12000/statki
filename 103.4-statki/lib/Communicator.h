#pragma once 
#include "Player.h"
#include "MapReader.h"
class Communicator {
public:
    Communicator() = default;
    void playerTurnMsg(std::shared_ptr<Player> p);
    void turnMsg(std::shared_ptr<Player> p);
    void winMsg(std::shared_ptr<Player> p);
    void showMaps(std::shared_ptr<Player> p);
    void welcomeMsg();
};