#pragma once
#include "Field.h"
#include "Ship.h"
#include <vector>
#include <memory>
class Ship;
class Map {
private:
    std::vector<std::vector<std::shared_ptr<Field>>> fields_;
    int sizeX_, sizeY_;
public:
    Map(std::vector<std::vector<std::shared_ptr<Field>>> fields);
    //do usuniecia
    Map(int rows, int cols);
    void show();
    void placeShip(Ship ship);
    void showForEnemy();
    std::shared_ptr<Field> getField(int x, int y) const;
    void ShipHit(bool change, int x, int y);
};