#include "Map.h"
#include <iostream>
#include <vector>
#include <sstream>


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

void Map::moveShip(int shipnr, Coordinates coords, orientation orientation) {
    auto old_pos = ships_[shipnr].getPositionOnMap();
    std::vector<std::vector<std::shared_ptr<Field>>> testfields = fields_;
    for( auto field : old_pos) {
        testfields[field->getx()][field->gety()]->setStatus(FieldStatus::zero);
    }
    std::vector<std::shared_ptr<Field>> newPosition = ships_[shipnr].predictNewPosition(coords, orientation);
    if (canPlaceShip(newPosition,testfields)) {
        for( auto field : old_pos) {
            fields_[field->getx()][field->gety()]->setStatus(FieldStatus::zero);
        }
        ships_[shipnr].move(coords, orientation);
        for( auto field : ships_[shipnr].getPositionOnMap()) {
            fields_[field->getx()][field->gety()]->setStatus(FieldStatus::one);
        }
    }
    else {
        std::cout << "nie mozna ruszyc statku w to miejsce" << std::endl;
    }
}

bool Map::canPlaceShip(std::vector<std::shared_ptr<Field>> position, std::vector<std::vector<std::shared_ptr<Field>>> testfields) const {
    for (auto field : position) {
        if (field->getx() < 0 || field->getx() >= sizeX_) {
            return false;
        }
        if (field->gety() < 0 || field->gety() >= sizeY_) {
            return false;
        }
        if(testfields[field->getx()][field->gety()]->getStatus() == FieldStatus::one) {
            return false;
        }
        if(!areNeigboursFieldsFree(field, testfields)) {
            return false;
        }
    }
    return true;
}
//warunek jak jestem na brzegu mapy zeby nie wyjezdzac poza mape 

bool Map::areNeigboursFieldsFree(std::shared_ptr<Field> field, std::vector<std::vector<std::shared_ptr<Field>>> testfields) const {
    int x = field->getx();
    int y = field->gety();
    
    std::vector<Coordinates>neighbours = {{x-1 ,y}, {x+1, y}, {x, y-1}, {x, y+1}};

    for (auto neighbour : neighbours) {
        std::cout << neighbour.x << " " << neighbour.y << std::endl;
        if (neighbour.x >= sizeX_ || neighbour.x < 0 || neighbour.y >= sizeY_ || neighbour.y < 0) {
            std::cout << "poza mapa" << x << y << std::endl;
        }
        else {
            if(testfields[neighbour.x][neighbour.y]->getStatus() == FieldStatus::one) {
                return false;
            }
        }   
    }
    return true;
}

std::string Map::getMapAsString() {
    std::stringstream ss;
    for(auto row : fields_) {
        for(auto col : row) {
            ss << col->getStatusToDisplay() << "\t";
        }
        ss << std::endl;
    }
    return ss.str();
}

std::string Map::getMapForEnemyAsString() {
    std::stringstream ss;
    for(auto row : fields_) {
        for(auto col : row) {
            if(col->isHidden())
                ss << "?" << "\t";
            else
                ss << col->getStatusToDisplay() << "\t";
        }
        ss << std::endl;
    }
    return ss.str();
}

void Map::showShipsHeads() {
    for(int i = 0; i < ships_.size(); i++) {
        std::cout << "row:" << ships_[i].getPositionOnMap()[0]->getx() << 
            " col: " << ships_[i].getPositionOnMap()[0]->gety() <<
            " number: " << i << std::endl;
    }
}


