
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

int main()
{
    std::cout << "Witaj w symulatorze gry w statki ver 1.0\n";
    Map testmap(5, 5);
    std::vector<std::pair<int, int>> pos;
    int x, y;
    for (int i = 0; i < 5; i++)
    {
        x = 0;
        y = i;
        pos.push_back(std::make_pair(x, y));
    }
    Ship ship1(pos);
    testmap.placeShip(ship1);
    Map testmap2(5, 5);
    std::vector<std::pair<int, int>> pos2;
    for (int i = 0; i < 5; i++)
    {
        x = 0;
        y = i;
        pos2.push_back(std::make_pair(x, y));
    }
    Ship ship2(pos2);
    testmap2.placeShip(ship2);
    std::vector<Ship> ships1 = {ship1};
    std::vector<Ship> ships2 = {ship2};
    std::shared_ptr<Map> map1 = std::make_shared<Map>(testmap);
    std::shared_ptr<Map> map2 = std::make_shared<Map>(testmap2);
    std::pair<std::shared_ptr<Map>, std::shared_ptr<Map>> maps1 = std::make_pair(map1, map2);
    std::pair<std::shared_ptr<Map>, std::shared_ptr<Map>> maps2 = std::make_pair(map2, map1);
    Player p1("Michał", maps1);
    Player p2("Maciek", maps2);
    p1.selectTarget(0, 2);
//    p2.checkStatus();
//    testmap2.show();
//    map2->show();
    map2->updateShips();
    map2->moveShip(0, 0, 2, orientation::vertically);
    map2->updateShips();

    auto m =  map2->getShips();
    for (const auto& num : m) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    map2->show();
    std::cout<<p2.hasShips();
    std::cout << std::endl;
//    p2.getMyMap().show();
    std::cout << std::endl;
    p1.selectTarget(1, 2);
    p2.checkStatus();
//    testmap2.show();
    std::cout << std::endl;
    testmap2.moveShip(0, 2, 0, orientation::horizontally);
//    testmap2.show();


    return 0;
}
