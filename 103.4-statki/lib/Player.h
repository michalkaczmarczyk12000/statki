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
#include "Coordinates.h"
class Ship;
class Map;
struct maps {
    std::pair<std::shared_ptr<Map>, std::shared_ptr<Map>> maps;
};


class Player {
public:
    Player(std::string name, maps playerMaps,  int rank=1000);
    void placeShip(Ship ship);
    int getRank() const;
    void changeRank(int points);
    bool hasShips() const;
    Map getMyMap() const;
    Map getEnemyMap() const;
    void createShip(std::vector<Coordinates> positionOnMap);
    virtual Coordinates shoot();
    void updateStatus();
    bool canPlaceShip() const;
    virtual ~Player();
    void selectTarget(Coordinates coords);
protected:
    std::string name_;
    maps maps_;
    int rank_;
};


#endif //INC_103_4_STATKI_PLAYER_H
