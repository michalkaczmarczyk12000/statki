//
// Created by michal on 06.12.23.
//

#include "Player.h"


Player::Player(std::string name, std::pair<Map, Map>maps,  int rank) : name_(name), maps_(maps),  rank_(rank) {
};

int Player::getRank() const {
    return rank_;
}

bool Player::canPlaceShip() const{
    //chwilowo zakładamy, że można stawaić statki wszędzie
    return true;
}

void Player::createShip(std::vector<std::pair<int, int>> positionOnMap) {
    if (canPlaceShip()) {
        Ship newShip(positionOnMap);
        placeShip(newShip);
    }
}
void Player::placeShip(Ship ship) {
        maps_.first.placeShip(ship);
}

void Player::changeRank(int points) {
    //zakładamy, że mogą być ujemne punkty
    rank_ += points;
}

void Player::selectTarget(int x, int y, Map enemyMap) {

    if(hasShips())
    {
        getMyMap().getShips()[0].shoot(x, y, enemyMap);
    }
}

bool Player::hasShips() const {
    return !(maps_.first.getShips().empty());
}



Map Player::getMyMap() const {
    return maps_.first;
}

Map Player::getEnemyMap() const {
    return maps_.second;
}

void Player::checkStatus() {
    maps_.first.updateShips();
}