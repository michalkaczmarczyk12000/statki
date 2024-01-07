//
// Created by michal on 06.12.23.
//

#include "RandomPlayer.h"


RandomPlayer::RandomPlayer(std::string name, Map map, int rank) : Player(name, map, rank) {
    for (int x = 0; x < map.sizeX; x++) {
        for (int y = 0; y < map.sizeY; y++) {
            possibleShoots.push_back({x, y});
        }
    }
};

std::pair<int, int> RandomPlayer::getRandom() const {

}

void RandomPlayer::randomSelectTarget() {

}
