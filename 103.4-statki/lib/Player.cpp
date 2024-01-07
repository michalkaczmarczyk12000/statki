//
// Created by michal on 06.12.23.
//

#include "Player.h"

Player::Player(std::string name, Map map) : name_(name), rank_(1000)  {
    maps_.push_back(map);
};
Player::Player(std::string name, int rank, Map map) : name_(name), rank_(rank) {
    maps_.push_back(map);
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