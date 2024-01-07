#include "Field.h"

Field::Field(int x, int y, bool isTakenByShip, bool isHidden) : x_(x), y_(y), 
    isTakenByShip_(isTakenByShip), isHidden_(isHidden){}

bool Field::isTakenByShip() const {
    return isTakenByShip_;
}

int Field::getx() const {
    return x_;
}

int Field::gety() const {
    return y_;
}

bool Field::isHidden() const {
    return isHidden_;
}

void Field::setTakenByShip(bool change) {
    isTakenByShip_ = change;
}