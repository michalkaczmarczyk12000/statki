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
    Player(std::string name, std::pair<std::shared_ptr<Map>, std::shared_ptr<Map>> maps,  int rank=1000);
    void placeShip(Ship ship);
    int getRank() const;
    void changeRank(int points);
    bool hasShips() const;
    Map getMyMap() const;
    Map getEnemyMap() const;
    void createShip(std::vector<std::pair<int,int>> positionOnMap);
    virtual void shoot();
    void checkStatus();
    bool canPlaceShip() const;
    virtual ~Player();
    void selectTarget(int x, int y);
protected:
    std::string name_;
    std::pair<std::shared_ptr<Map>, std::shared_ptr<Map>> maps_;
    int rank_;
};


#endif //INC_103_4_STATKI_PLAYER_H
