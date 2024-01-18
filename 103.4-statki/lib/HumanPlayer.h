//
// Created by michal on 06.12.23.
//

#ifndef INC_103_4_STATKI_HUMANPLAYER_H
#define INC_103_4_STATKI_HUMANPLAYER_H
#include "Player.h"

class HumanPlayer : public Player{
public:
    HumanPlayer(std::string name, maps playerMaps, int rank=1000);
    virtual Coordinates shoot() override;
    bool isChecked(Coordinates coords) const;
    void turn(int delay) override;
private:
    std::vector<Coordinates> lastShoots;
};


#endif //INC_103_4_STATKI_HUMANPLAYER_H
