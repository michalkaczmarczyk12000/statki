#include "Field.h"
#include <iostream>


Field::Field(Coordinates coords, FieldStatus status, bool isHidden) : x_(coords.x), y_(coords.y),
    status_(status), isHidden_(isHidden){}

FieldStatus Field::getStatus() const {
    return status_;
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
    x_ = x;
}

void Field::sety(int y) {
    y_ = y;
}