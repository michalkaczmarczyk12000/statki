#pragma once
#include "Field.h"
#include "Ship.h"
#include <vector>
#include <memory>
#include "Coordinates.h"
class Ship;
class Map {
private:
    std::vector<std::vector<std::shared_ptr<Field>>> fields_;
    int sizeX_, sizeY_;
    std::vector<Ship> ships_;
public:
    Map(int rows, int cols, std::vector<Ship> ships = {});
    void show();
    void placeShip(Ship ship);
    void showForEnemy();
    std::vector<Ship> setShips(std::vector<Ship> ships);
    int getSizeX() const;
    int getSizeY() const;

    std::shared_ptr<Field> getField(Coordinates coords) const;

    bool canPlaceShip() const;
    std::vector<Ship> getShips() const;
    void updateShips();

};