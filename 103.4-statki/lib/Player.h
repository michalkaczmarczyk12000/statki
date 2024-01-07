//
// Created by michal on 06.12.23.
//

#ifndef INC_103_4_STATKI_PLAYER_H
#define INC_103_4_STATKI_PLAYER_H
#include <string>
#include <vector>
//#include "Map.h"
//#include "Ship"
//#include "Field"
//#include "Ship.h"
// chwilowy brak implementacji klas zasßąpiony strukturami
struct Map{
    int sizeX = 10;
    int sizeY = 10;
};
struct Ship{
    void shoot(int x, int y, Map map);
};
struct Field{};


class Player {
public:
    Player(std::string name, Map map, int rank=1000);
    void placeShip(Ship ship, std::vector<Field> fields, Map map);
    int getRank() const;
    void changeRank(int points);
    bool hasShips() const;
    virtual void shoot();
protected:
    std::string name_;
    std::vector<Ship> ships_;
//    here we can have vector of std::pair if we can play more than one game at the same time
    std::pair<Map, Map> maps_;
    bool canPlaceShip() const;
    void selectTarget(int x, int y, Map opponentMap) ;

    int rank_;
};


#endif //INC_103_4_STATKI_PLAYER_H
