//
// Created by michal on 06.12.23.
//

#include "HumanPlayer.h"
#include <algorithm>
#include "Communicator.h"
HumanPlayer::HumanPlayer(std::string name, maps playerMaps, int rank) : Player(name, playerMaps, rank) {};

Coordinates HumanPlayer::shoot() {
}

bool HumanPlayer::isChecked(Coordinates coords) const {
    auto it = std::find(possibleShoots_.begin(), possibleShoots_.end(), coords);
    return (it != possibleShoots_.end());
}

void HumanPlayer::turn() {
    Communicator com;
    Coordinates coords;
    int decision = com.makeDecision();
    switch (decision) {
        case 1:
            coords = com.getCoords();
            selectTarget(coords);
            break;
        case 2:
            maps_.maps.first->show();
            maps_.maps.first->showShipsHeads();

            int shipnr;
            shipnr = com.getShipId();
            coords= com.getCoords();
            orientation shipOrientation;
            shipOrientation = com.getOrientation();
            moveShip(shipnr, coords, shipOrientation);
            break;
        default:
            com.alert("Popraw ruch!");
            turn();
            break;
    }
}