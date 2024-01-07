#include "Map.h"
#include <iostream>
#include <vector>

Map::Map(std::vector<std::vector<Field>> fields) : fields_(fields){}

Map::Map(int rows, int cols) {
    std::vector<std::vector<Field>> fields;
    for(int i = 0; i < rows; i++) {
        std::vector<Field> row = {};
        for(int j = 0; j < cols; j++) {
            row.push_back(Field());
        }
        fields.push_back(row);
    }
    fields_ = fields;
}

void Map::show() {
    for(auto row : fields_) {
        for(auto col : row) {
            std::cout << col.getIsTakenByShip() << "\t";
        }
        std::cout << std::endl;
    }
}

void Map::placeShip(std::shared_ptr<Ship> PShip) {
    for(auto field : PShip->getPositionOnMap()) {
        fields_[field.getx()][field.gety()] = field;
    }
}