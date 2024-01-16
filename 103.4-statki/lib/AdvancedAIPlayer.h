//
// Created by michal on 16.01.24.
//

#ifndef ADVANCEDAIPLAYER_H
#define ADVANCEDAIPLAYER_H


#include "Coordinates.h"
#include "RandomPlayer.h"
class AdvancedAIPlayer : public RandomPlayer {
public:
    AdvancedAIPlayer(std::string name, maps playerMaps, int rank=1000);
    Coordinates shoot() override;
    void handleHit(Coordinates coords);
    void resetHitCoordinates();
private:
    std::vector<Coordinates> lastHitCoordinates_;
};

#endif // ADVANCEDAIPLAYER_H
