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
    Map(int rows, int cols);
    void show();
    void placeShip(Ship ship);
    void showForEnemy();
    int getSizeX() const;
    int getSizeY() const;
    std::shared_ptr<Field> getField(int x, int y) const;
};