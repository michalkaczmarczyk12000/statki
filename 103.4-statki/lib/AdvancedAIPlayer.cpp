//
// Created by michal on 16.01.24.
//
#include <iostream>

#include "AdvancedAIPlayer.h"
AdvancedAIPlayer::AdvancedAIPlayer(std::string name, maps playerMaps, int rank)
        : RandomPlayer(name, playerMaps, rank) {
}

Coordinates AdvancedAIPlayer::shoot() {
    if (!lastHitCoordinates_.empty()) {
        int x = lastHitCoordinates_.back().x;
        int y = lastHitCoordinates_.back().y;
        std::vector<Coordinates>neighbors = {{x-1 ,y}, {x+1, y}, {x, y-1},
                                             {x, y+1}};
        std::sort(neighbors.begin(), neighbors.end());
        std::sort(possibleShoots_.begin(), possibleShoots_.end());
        std::vector<Coordinates> commonElements;


        std::set_intersection(neighbors.begin(), neighbors.end(),
                              possibleShoots_.begin(), possibleShoots_.end(),
                              std::back_inserter(commonElements));
            if(!commonElements.empty()) {
                auto target = commonElements[0];
                lastHitCoordinates_.push_back(target);
                possibleShoots_.erase(std::remove(possibleShoots_.begin(), possibleShoots_.end(), target),
                                      possibleShoots_.end());
                selectTarget(target);
            }
    } else {
        Coordinates last_shoot = RandomPlayer::shoot();
        handleHit(last_shoot);
        if(maps_.maps.second->getField(last_shoot)->getStatusToDisplay() != 'x'){
            resetHitCoordinates();
        }
    }
    return lastHitCoordinates_.back();
}


void AdvancedAIPlayer::handleHit(Coordinates coordinates) {
    lastHitCoordinates_.push_back({coordinates.x, coordinates.y});
}

void AdvancedAIPlayer::resetHitCoordinates() {
    lastHitCoordinates_.clear();
}

