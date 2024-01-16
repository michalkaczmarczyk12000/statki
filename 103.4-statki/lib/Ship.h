#pragma once
#include <vector>
#include <memory>
#include "Field.h"
#include "Map.h"
#include "Player.h"
#include "Coordinates.h"
class Map;
class Ship {
private:
    static int countOfShips;
    int id_;
    int size_;
    std::vector<std::shared_ptr<Field>> positionOnMap_;
public:
    Ship(std::vector<Coordinates> positionOnMap);
    std::vector<std::shared_ptr<Field>> getPositionOnMap() const;
    void shoot(int x, int y, std::shared_ptr<Map> map);
    void updateShip();
};

