#pragma once
#include <vector>
#include "Field.h"
class Ship {
private:
    static int countOfShips;
    int id_;
    int size_;
    std::vector<Field> positionOnMap_;
public:
    Ship(int size, std::vector<std::pair<int,int>> positionOnMap);
    std::vector<Field> getPositionOnMap();
};

