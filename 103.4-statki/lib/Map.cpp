#include "Map.h"
#include <iostream>
#include <vector>


Map::Map(int rows, int cols, std::vector<Ship> ships) : sizeX_(rows), 
    sizeY_(cols), ships_{ships}{
    std::vector<std::vector<std::shared_ptr<Field>>> fields;
    for(int i = 0; i < rows; i++) {
        std::vector<std::shared_ptr<Field>> row = {};
        for(int j = 0; j < cols; j++) {
            row.push_back(std::make_shared<Field>(i,j));
        }
        fields.push_back(row);
    }
    if(!ships_.empty()) {
        for(auto ship : ships_) {
            placeShip(ship);
        }
    }
    fields_ = fields;
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