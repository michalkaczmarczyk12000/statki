//
// Created by michal on 16.01.24.
//

#include "Coordinates.h"
Coordinates::Coordinates(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}

bool Coordinates::operator==(const Coordinates& other) const {
    return (x == other.x) && (y == other.y);
}
bool Coordinates::operator<(const Coordinates& other) const {
    // Porównanie najpierw po x, a jeśli są równe, to po y
    return (x < other.x) || ((x == other.x) && (y < other.y));
}