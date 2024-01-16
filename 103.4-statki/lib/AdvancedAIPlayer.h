//
// Created by michal on 16.01.24.
//

#ifndef STATKI_ADVANCEDAIPLAYER_H
#define STATKI_ADVANCEDAIPLAYER_H
#include "PlayerAI.h"

class AdvancedAIPlayer : public PlayerAI{
public:
    AdvancedAIPlayer(std::string name, maps playerMaps, int rank);
    void shoot() override;
private:

};


#endif //STATKI_ADVANCEDAIPLAYER_H
