//
// Created by michal on 06.12.23.
//

#ifndef INC_103_4_STATKI_GAME_H
#define INC_103_4_STATKI_GAME_H
#include "Player.h"
#include "GameRules.h"
#include "RandomPlayer.h"
#include "Player.h"
#include "Communicator.h"
#include <memory>
class Game {
private:
    std::shared_ptr<Player> p1_, p2_;
    void turn(std::shared_ptr<Player> player, int delay);
    bool isEnded(std::shared_ptr<Player> player, std::shared_ptr<Player> p2);
    Communicator com_;
public:
    Game(std::shared_ptr<Player> p1, std::shared_ptr<Player> p2, Communicator com);
    void startGame();
    void endGame();
    void winner();
    void prepGame();
};


#endif //INC_103_4_STATKI_GAME_H
