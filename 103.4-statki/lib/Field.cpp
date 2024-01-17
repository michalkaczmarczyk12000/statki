#include "Field.h"
#include <iostream>


Field::Field(Coordinates coords, FieldStatus status, bool isHidden) : coords_(coords),
    status_(status), isHidden_(isHidden){}

FieldStatus Field::getStatus() const {
    return status_;
}

int Field::getx() const {
    return coords_.x;
}

int Field::gety() const {
    return coords_.y;
}

bool Field::isHidden() const {
    return isHidden_;
}

void Field::setStatus(FieldStatus status) {
    status_ = status;
}

void Field::setHidden(bool change) {
    isHidden_ = change;
}

char Field::getStatusToDisplay() const {
    return static_cast<char>(status_);
}

void Field::setx(int x) {
    coords_.x = x;
}

void Field::sety(int y) {
    coords_.y = y;
}

Coordinates Field::getCoords() const {
    return coords_;
}