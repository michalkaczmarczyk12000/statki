//
// Created by michal on 16.01.24.
//

#include "PlayerAI.h"

PlayerAI::PlayerAI(std::string name, std::pair<std::shared_ptr<Map>, std::shared_ptr<Map>> maps, int rank)
        : Player(std::move(name), maps, rank) {
    // Additional initialization specific to AIPlayer if needed
}

PlayerAI::~PlayerAI() {

}