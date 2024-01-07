//
// Created by michal on 06.12.23.
//

#include "Player.h"


Player::Player(std::string name, Map map, int rank) : name_(name), rank_(rank) {
    maps_.first = map;
};

int Player::getRank() const {
    return rank_;
}

bool Player::canPlaceShip() {
    //chwilowo zakładamy, że można stawaić statki wszędzie
    return true;
}

void Player::placeShip(Ship ship, std::vector<Field> fields, Map map) {
    if(canPlaceShip())
    {
        ships_.push_back(ship);

        //ship.setPosition(fields);

    }
}

void Player::changeRank(int points) {
    //zakładamy, że mogą być ujemne punkty
    rank_ += points;
}

void Player::selectTarget(int x, int y, Map opponentMap) {
    if(!ships_.empty())
    {
        ships_[0].shoot(x, y, opponentMap);
    }
}

