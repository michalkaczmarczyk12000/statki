#pragma once 
#include "Player.h"
#include "HumanPlayer.h"
#include "RandomPlayer.h"
#include "AdvancedAIPlayer.h"
#include "MapReader.h"
class Communicator {
public:
    Communicator() = default;
    void playerTurnMsg(std::shared_ptr<Player> p);
    void turnMsg(std::shared_ptr<Player> p);
    void winMsg(std::shared_ptr<Player> p);
    void showMaps(std::shared_ptr<Player> p);
    void welcomeMsg();
    void loadNames(std::string& name1, std::string& name2);
    void loadFilenames(std::string& filename1, std::string& filename2);
    void selecPlayers(std::shared_ptr<Player> p1, std::shared_ptr<Player> p2,
         maps maps1, maps maps2, std::string name1, std::string name2);
};