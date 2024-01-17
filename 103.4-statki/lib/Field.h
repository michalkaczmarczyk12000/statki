#pragma once
#include "Coordinates.h"
enum class FieldStatus : char {
    x = 'x',
    zero = '0',
    one = '1',
    miss = 'm'
};
enum class orientation : char {
    horizontally = 'h',
    vertically = 'v'
};
class Field {
private:
    Coordinates coords_;
    FieldStatus status_;
    bool isHidden_;
public:
    Field(Coordinates coords = {0 ,0}, FieldStatus state = FieldStatus::zero, bool isHidden = true);
    FieldStatus getStatus() const;
    int getx() const;
    int gety() const;
    Coordinates getCoords() const;
    bool isHidden() const;
    void setStatus(FieldStatus status);
    void setHidden(bool change);
    char getStatusToDisplay() const;
    void setx(int x);
    void sety(int y);
};