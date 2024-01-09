//
// Created by michal on 06.12.23.
//

#ifndef INC_103_4_STATKI_PLAYER_H
#define INC_103_4_STATKI_PLAYER_H
#include <string>
#include <vector>
#include "Map.h"
#include "Field.h"
#include "Ship.h"



class Player {
public:
    Player(std::string name, std::pair<Map, Map>, std::vector<Ship> ships, int rank=1000);
    void placeShip(Ship ship, std::vector<Field> fields, Map map);
    int getRank() const;
    void changeRank(int points);
    bool hasShips() const;
    Map getMyMap() const;
    Map getEnemyMap() const;
    void updateShips();
    virtual void shoot() = 0;
protected:
    std::string name_;
    std::vector<Ship> ships_;
    std::pair<Map, Map> maps_;
    bool canPlaceShip() const;
    void selectTarget(int x, int y, Map enemyMap);
    int rank_;
};


#endif //INC_103_4_STATKI_PLAYER_H
