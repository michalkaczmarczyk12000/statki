#pragma once
#include "Field.h"
#include "Ship.h"
#include <vector>
#include <memory>
class Map {
private:
    std::vector<std::vector<Field>> fields_;
public:
    Map(std::vector<std::vector<Field>> fields);
    //do usuniecia
    Map(int rows, int cols);
    void show();
    void placeShip(std::shared_ptr<Ship> PShip);
};