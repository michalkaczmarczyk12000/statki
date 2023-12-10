//
// Created by michal on 06.12.23.
//

#ifndef INC_103_4_STATKI_PLAYER_H
#define INC_103_4_STATKI_PLAYER_H
#include <string>
#include <vector>
//#include "Ship.h"
// chwilowy brak implementacji klas zasßąpiony strukturami
struct Ship{};
struct Field{};
struct Map{};

class Player {
public:
    Player(std::string name);
    Player(std::string name, int rank);
    void placeShip(Ship ship, std::vector<Field> fields, Map map);
    int getRank() const;
    void changeRank(int points);
private:
    std::string name_;
    std::vector<Ship> ships_;
    std::vector<Map> maps_;
    bool canPlaceShip();
    int rank_;
};


#endif //INC_103_4_STATKI_PLAYER_H
