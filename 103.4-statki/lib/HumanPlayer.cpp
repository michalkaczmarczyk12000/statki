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
            maps_.maps.first->show();
            maps_.maps.first->showShipsHeads();
            std::cout<<"Podaj statek";
            int shipnr;
            std::cin >> shipnr;
            std::cout << "Podaj rząd i kolumne, do które ma się przemieścić dziób statku:" << std::endl;
            int xx;
            int yy;
            std::cin >> xx;
            std::cin >> yy;
            std::cout << "Podaj orientacje statku v - pionowo, h - poziomo:" << std::endl;
            char orient;
            std::cin >> orient;
            orientation shipOrientation;
            if(orient == 'h')
                shipOrientation = orientation::horizontally;
            else
                shipOrientation = orientation::vertically;
            moveShip(shipnr, Coordinates(xx, yy), shipOrientation);
            break;
        default:
            std::cout<<"Popraw ruch";
            turn(100);
            break;
    }
}