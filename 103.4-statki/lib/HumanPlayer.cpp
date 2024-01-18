//
// Created by michal on 06.12.23.
//

#include "HumanPlayer.h"
#include <algorithm>
HumanPlayer::HumanPlayer(std::string name, maps playerMaps, int rank) : Player(name, playerMaps, rank) {};

Coordinates HumanPlayer::shoot() {
    int x;
    int y;
    bool exist = false;
    std::cout<<"Podaj współrzędne: ";
    std::cin>>x>>y;
    Coordinates coordinates(x, y);
    for (auto coord : lastShoots) {
        if (coord == coordinates) {
            exist = true;
            break;
        }
    }
    if (exist){
        std::cout<<"Ponów strzał\n";
        shoot();
    }
    else {
    selectTarget(coordinates);
    lastShoots.push_back(coordinates);
    }
    return coordinates;
}

bool HumanPlayer::isChecked(Coordinates coords) const {
    auto it = std::find(possibleShoots_.begin(), possibleShoots_.end(), coords);
    return (it != possibleShoots_.end());
}

void HumanPlayer::turn(int delay) {
    std::cout<<"Strzał(1) Ruch(2): " ;
    int decision;
    std::cin>>decision;
    switch (decision) {
        case 1:
            shoot();
            break;
        case 2:
            std::cout<<"Podaj statek";
//            moveShip()
            break;
        default:
            std::cout<<"Popraw ruch";
            turn(100);
            break;
    }
}