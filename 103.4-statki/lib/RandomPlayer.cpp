//
// Created by michal on 06.12.23.
//

#include "RandomPlayer.h"
#include <stdexcept>

RandomPlayer::RandomPlayer(std::string name, maps playerMaps, int rank) : Player(name, playerMaps,  rank), gen(std::chrono::system_clock::now().time_since_epoch().count()) {


};

Coordinates RandomPlayer::getRandomField() {
    if (!possibleShoots_.empty()) {
        std::shuffle(possibleShoots_.begin(), possibleShoots_.end(), gen);
        Coordinates shotCoordinates = possibleShoots_.back();
        possibleShoots_.pop_back();
        return shotCoordinates;
    }
    throw std::runtime_error("Here I will add my own error, I promise");
}

Coordinates RandomPlayer::randomSelectTarget() {
    auto targetField = getRandomField();
    selectTarget(targetField);
    return targetField;
}


Coordinates RandomPlayer::shoot() {
    auto target = randomSelectTarget();
    return target;
}

RandomPlayer::~RandomPlayer() {

}

