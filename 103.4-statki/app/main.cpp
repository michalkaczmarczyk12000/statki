
#include <iostream>
#include <vector>
#include <memory>
#include "../lib/Field.h"
#include "../lib/Map.h"
#include "../lib/Ship.h"
#include "../lib/Game.h"
#include "../lib/Player.h"
#include "../lib/RandomPlayer.h"
#include "../lib/MapReader.h"
#include "../lib/Writer.h"
#include "../lib/AdvancedAIPlayer.h"
#include "../lib/Communicator.h"

int main()
{
    Communicator com("history.txt");
    Game g1(com);
    g1.prepGame();
    g1.startGame();

    return 0;
}
