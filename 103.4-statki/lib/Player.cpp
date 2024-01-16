//
// Created by michal on 06.12.23.
//

#include "Player.h"


Player::Player(std::string name, maps playerMaps,  int rank) : name_(name), maps_(playerMaps),  rank_(rank) {
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
        maps_.maps.first->placeShip(newShip);
    }
}
void Player::placeShip(Ship ship) {
    maps_.maps.first->placeShip(ship);
}

void Player::changeRank(int points) {
    //zakładamy, że mogą być ujemne punkty
    rank_ += points;
}

void Player::selectTarget(int x, int y) {

    if(hasShips())
    {
        maps_.maps.first->getShips()[0].shoot(x, y, maps_.maps.second);
    }
}

bool Player::hasShips() const {
    return !(maps_.maps.first->getShips().empty());
}



Map Player::getMyMap() const {
    return *maps_.maps.first;
}

Map Player::getEnemyMap() const {
    return *maps_.maps.second;
}

void Player::updateStatus() {
    maps_.maps.first->updateShips();
}

Player::~Player() {

}
void Player::shoot() {
    // Implementation of shoot()
}
