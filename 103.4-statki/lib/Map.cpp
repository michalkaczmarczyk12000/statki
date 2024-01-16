#include "Map.h"
#include <iostream>
#include <vector>


Map::Map(int rows, int cols) : sizeX_(rows), sizeY_(cols){
    std::vector<std::vector<std::shared_ptr<Field>>> fields;
    for(int i = 0; i < rows; i++) {
        std::vector<std::shared_ptr<Field>> row = {};
        for(int j = 0; j < cols; j++) {
            row.push_back(std::make_shared<Field>(i,j));
        }
        fields.push_back(row);
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

std::shared_ptr<Field> Map::getField(int x, int y) const{
    return fields_[x][y];
}

int Map::getSizeX() const {
    return sizeX_;
}

int Map::getSizeY() const {
    return sizeY_;
}

