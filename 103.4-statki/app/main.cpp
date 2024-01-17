
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

    std::cout << "Witaj w symulatorze gry w statki ver 1.0\n";
    Map testmap(10, 10);
    std::vector<Coordinates> pos;
    int x, y;
    for (int i = 0; i < 5; i++)
    {
        x = 3;
        y = i;
        pos.push_back(Coordinates(x, y));
    }
    Ship ship1(pos);
    testmap.placeShip(ship1);
    Map testmap2(10, 10);
    std::vector<Coordinates> pos2;
    for (int i = 0; i < 5; i++)
    {
        x = 3;
        y = i;
        pos2.push_back(Coordinates(x, y));
    }
    Ship ship2(pos2);
    testmap2.placeShip(ship2);
    std::vector<Ship> ships1 = {ship1};
    std::vector<Ship> ships2 = {ship2};
    std::shared_ptr<Map> map1 = std::make_shared<Map>(testmap);
    std::shared_ptr<Map> map2 = std::make_shared<Map>(testmap2);
    maps maps1 = {
        std::make_pair(std::make_shared<Map>(testmap), std::make_shared<Map>(testmap2))};

    maps maps2 = {
        std::make_pair(std::make_shared<Map>(testmap2), std::make_shared<Map>(testmap))};
    RandomPlayer p1("Michał", maps1);
    AdvancedAIPlayer p2("Maciek", maps2);
    Communicator com;
    Game g1(std::make_shared<RandomPlayer>(p1), std::make_shared<AdvancedAIPlayer>(p2), com);
    g1.startGame();

    // p1.updateStatus();
    // p1.getMyMap().show();
    // std::cout << std::endl;
    // testmap.show();

    // std::cout << std::endl;
    // p1.moveShip(0, Coordinates(1,5), orientation::horizontally);
    // p1.getMyMap().show();

    // p2.selectTarget(Coordinates(1,5));
    // p1.updateStatus();

    // std::cout << std::endl;
    // p1.getMyMap().show();
    // std::cout << std::endl;
    // testmap.show();

    // std::cout << p2.hasShips() << std::endl;
    // std::cout << p1.hasShips() << std::endl;


    return 0;
}
