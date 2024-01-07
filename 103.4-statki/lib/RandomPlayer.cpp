//
// Created by michal on 06.12.23.
//

#include "RandomPlayer.h"


RandomPlayer::RandomPlayer(std::string name, Map map, int rank) : Player(name, map, rank), gen(std::chrono::system_clock::now().time_since_epoch().count()) {
    for (int x = 0; x < map.sizeX; x++) {
        for (int y = 0; y < map.sizeY; y++) {
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
    return std::make_pair(-1, -1);
}

void RandomPlayer::randomSelectTarget() {
    auto targetField = getRandomField();
    selectTarget(targetField.first, targetField.second, maps_.second);
}

