//
// Created by michal on 06.12.23.
//

#include "RandomPlayer.h"
#include <stdexcept>

RandomPlayer::RandomPlayer(std::string name, std::pair<Map, Map> map, std::vector<Ship> ships,int rank) : Player(name, map, ships, rank), gen(std::chrono::system_clock::now().time_since_epoch().count()) {
    for (int x = 0; x < map.second.getSizeX(); x++) {
        for (int y = 0; y < map.second.getSizeY(); y++) {
            possibleShoots_.push_back({x, y});
        }
    }
};

std::pair<int, int> RandomPlayer::getRandomField() {
    if (!possibleShoots_.empty()) {
        std::shuffle(possibleShoots_.begin(), possibleShoots_.end(), gen);
        std::pair<int, int> shotCoordinates = possibleShoots_.back();
        possibleShoots_.pop_back();
        return shotCoordinates;
    }
    //we can add exception now
    throw std::runtime_error("Here I will add my own error, I promise");
}

void RandomPlayer::randomSelectTarget() {
    auto targetField = getRandomField();
    selectTarget(targetField.first, targetField.second, maps_.second);
}


void RandomPlayer::shoot() {
    randomSelectTarget();
}

