//
// Created by michal on 06.12.23.
//

#include "Player.h"

Player::Player(std::string name) : name_(name), rank_(1000) {};
Player::Player(std::string name, int rank) : name_(name), rank_(rank) {};

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
        //tutaj implmenetujemy coś takiego
        ships_.push_back(ship);

        //ship.setPosition(fields);

    }
}

void Player::changeRank(int points) {
    //zakładamy, że mogą być ujemne punkty
    rank_ += points;
}