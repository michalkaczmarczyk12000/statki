//
// Created by michal on 06.12.23.
//

#ifndef INC_103_4_STATKI_GAME_H
#define INC_103_4_STATKI_GAME_H
#include "Player.h"
#include "GameRules.h"
#include "RandomPlayer.h"
#include <memory>
class Game {
private:
    std::shared_ptr<Player> p1_, p2_;
    GameRules gameRules_;

public:
    Game(std::shared_ptr<Player> p1, std::shared_ptr<Player> p2, GameRules gameRules);
    void startGame();
    void endGame();
    void winner();
};


#endif //INC_103_4_STATKI_GAME_H
