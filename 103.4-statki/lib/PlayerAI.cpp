//
// Created by michal on 16.01.24.
//

#include "PlayerAI.h"

PlayerAI::PlayerAI(std::string name, maps playerMaps, int rank)
        : Player(std::move(name), playerMaps, rank) {
    // Additional initialization specific to AIPlayer if needed
}

PlayerAI::~PlayerAI() {

}