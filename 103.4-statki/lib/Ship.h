#pragma once
#include <vector>
#include <memory>
#include "Field.h"
#include "Map.h"
#include <iostream>
class Map;
class Ship {
private:
    static int countOfShips;
    int id_;
    int size_;
    std::vector<std::shared_ptr<Field>> positionOnMap_;
    // <std::shared_ptr<Field> head;
    // int orientation; (1 - poziomo, 2 - pionowo)
    // int size
public:
    Ship(std::vector<std::pair<int,int>> positionOnMap);
    std::vector<std::shared_ptr<Field>> getPositionOnMap() const;
    void shoot(int x, int y, std::shared_ptr<Map> map);
    void updateShip();
    void move(int x, int y, orientation orientation);
    friend std::ostream& operator<<(std::ostream& os, const Ship& ship) {
        os << "Ship ID: " << ship.id_ << ", Size: " << ship.size_ << "\n";
        os << "Position on Map:\n";
        for (const auto& field : ship.positionOnMap_) {
            os << "  - (" << field->getx() << ", " << field->gety() << ")\n";
        }
        return os;
    }
};

