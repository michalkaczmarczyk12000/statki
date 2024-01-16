//
// Created by michal on 06.12.23.
//

#include "HumanPlayer.h"
#include <algorithm>
HumanPlayer::HumanPlayer(std::string name, maps playerMaps, int rank) : Player(name, playerMaps, rank) {};

Coordinates HumanPlayer::shoot() {
    //Coordinates getUserInput(); to jest od interfejsu kompunikacji gracz z komputerem
    Coordinates coords(0,0);
    if (!isChecked(coords)){
    selectTarget(coords);}
    else
    {
        //powrót do naszego userInputa();
    }
    return coords;
}

bool HumanPlayer::isChecked(Coordinates coords) const {
    auto it = std::find(possibleShoots_.begin(), possibleShoots_.end(), coords);
    return (it != possibleShoots_.end());
}