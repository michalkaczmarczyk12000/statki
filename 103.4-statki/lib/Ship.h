#pragma once
#include <vector>
#include <memory>
#include "Field.h"
#include "Map.h"
class Map;
class Ship {
private:
    static int countOfShips;
    int id_;
    int size_;
    std::vector<std::shared_ptr<Field>> positionOnMap_;
public:
    Ship(int size, std::vector<std::pair<int,int>> positionOnMap);
    std::vector<std::shared_ptr<Field>> getPositionOnMap() const;
    void shoot(int x, int y, Map map);
    void updateShip();
};

