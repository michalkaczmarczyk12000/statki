#include "Field.h"

Field::Field(int x, int y, bool isTakenByShip) : x_(x), y_(y), isTakenByShip_(isTakenByShip){}

bool Field::getIsTakenByShip() {
    return isTakenByShip_;
}

int Field::getx() {
    return x_;
}

int Field::gety() {
    return y_;
}