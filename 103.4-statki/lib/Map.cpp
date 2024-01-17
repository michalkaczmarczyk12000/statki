#include "Map.h"
#include <iostream>
#include <vector>


Map::Map(int rows, int cols, std::vector<Ship> ships) : sizeX_(rows), sizeY_(cols), ships_{ships} {

    fields_.resize(rows, std::vector<std::shared_ptr<Field>>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fields_[i][j] = std::make_shared<Field>(Coordinates(i, j));
        }
    }

    if (!ships_.empty()) {
        for (auto& ship : ships_) {
            setShipPosition(ship);
        }
    }
}

void Map::show() {
    for(auto row : fields_) {
        for(auto col : row) {
            std::cout << col->getStatusToDisplay() << "\t";
        }
        std::cout << std::endl;
    }
}


void Map::placeShip(Ship ship) {
    ships_.push_back(ship);
    setShipPosition(ship);
}

void Map::setShipPosition(Ship ship) {
    for(auto field : ship.getPositionOnMap()) {
        fields_[field->getx()][field->gety()] = field;
    }
}

void Map::showForEnemy() {
    for(auto row : fields_) {
        for(auto col : row) {
            if(col->isHidden())
                std::cout << "?" << "\t";
            else
                std::cout << col->getStatusToDisplay() << "\t";
        }
        std::cout << std::endl;
    }
}

std::shared_ptr<Field> Map::getField(Coordinates coords) const{
    return fields_[coords.x][coords.y];
}

int Map::getSizeX() const {
    return sizeX_;
}

int Map::getSizeY() const {
    return sizeY_;
}

std::vector<Ship> Map::getShips() const {
    return ships_;
}

void Map::updateShips() {
    for (auto it = ships_.begin(); it != ships_.end();) {
        (*it).updateShip();
        if ((*it).getPositionOnMap().empty()) {
            it = ships_.erase(it);
        } else {
            ++it;
        }
    }
}

std::vector<Ship> Map::setShips(std::vector<Ship> ships) {
    ships_ = ships;
}

void Map::moveShip(int shipnr, int x, int y, orientation orientation) {
    auto old_pos = ships_[shipnr].getPositionOnMap();
    for( auto field : old_pos) {
        fields_[field->getx()][field->gety()] = std::make_shared<Field>(Coordinates(field->getx(),field->gety()),FieldStatus::zero,field->isHidden());
    }
    ships_[shipnr].move(x, y, orientation);
    for( auto field : ships_[shipnr].getPositionOnMap()) {
        fields_[field->getx()][field->gety()] = std::make_shared<Field>(Coordinates(field->getx(),field->gety()),field->getStatus(),field->isHidden());
    }
}