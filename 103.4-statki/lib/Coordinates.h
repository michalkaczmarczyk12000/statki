//
// Created by michal on 16.01.24.
//

#ifndef STATKI_COORDINATES_H
#define STATKI_COORDINATES_H


class Coordinates  {
public:
    int x;
    int y;
    Coordinates(int xCoord, int yCoord);
    Coordinates() = default;
    bool operator==(const Coordinates& other) const;
    bool operator<(const Coordinates& other) const;
};


#endif //STATKI_COORDINATES_H
