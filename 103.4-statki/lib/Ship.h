#pragma once
#include <vector>
#include "Map.h"
#include "Field.h"
class Ship {
private:
    int size_;
    std::vector<Field> positionOnMap;
};
