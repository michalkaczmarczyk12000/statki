//
// Created by michal on 06.12.23.
//

#include "Player.h"


Player::Player(std::string name, std::pair<Map, Map>maps, std::vector<Ship> ships, int rank) : name_(name), maps_(maps), ships_(ships), rank_(rank) {
};

int Player::getRank() const {
    return rank_;
}

bool Player::canPlaceShip() const{
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

void Player::selectTarget(int x, int y, Map enemyMap) {
    if(!ships_.empty())
    {
        ships_[0].shoot(x, y, enemyMap);
    }
}

bool Player::hasShips() const {
    return !ships_.empty();
}

void Player::updateShips() {
    for (auto it = ships_.begin(); it != ships_.end();) {
        (*it).updateShip();
        if ((*it).getPositionOnMap().empty()) {
            it = ships_.erase(it);
        } else {
            ++it;
        }
    }
}

Map Player::getMyMap() const {
    return maps_.first;
}

Map Player::getEnemyMap() const {
    return maps_.second;
}