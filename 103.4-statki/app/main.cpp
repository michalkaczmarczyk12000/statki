
#include <iostream>
#include <vector>
#include <memory>
#include "../lib/Field.h"
#include "../lib/Map.h"
#include "../lib/Ship.h"
#include "../lib/Game.h"
#include "../lib/Player.h"
#include "../lib/RandomPlayer.h"

int main()
{
    // std::cout << "Witaj w symulatorze gry w statki ver 1.0\n";
    // Map testmap(5,5);
    // std::vector<std::pair<int,int>> pos;
    // int x,y;
    // for (int i=0; i < 5; i ++) {
    //     x = 0;
    //     y = i;
    //     pos.push_back(std::make_pair(x,y));
    // }
    // Ship ship1(pos);
    // testmap.placeShip(ship1);
    // Map testmap2(5,5);
    // std::vector<std::pair<int,int>> pos2;
    // for (int i=0; i < 5; i ++) {
    //     x = 0;
    //     y = i;
    //     pos2.push_back(std::make_pair(x,y));
    // }
    // Ship ship2(pos2);
    // testmap2.placeShip(ship2);
    // std::vector<Ship> ships1 = {ship1};
    // std::vector<Ship> ships2 = {ship2};
    // GameRules grules;
    // testmap.setShips(ships1);
    // testmap2.setShips(ships2);
    // RandomPlayer p1("Michał", std::make_pair(testmap, testmap2));
    // RandomPlayer p2("Maciek",std::make_pair(testmap2, testmap));
    // Game g1(std::make_shared<RandomPlayer>(p1), std::make_shared<RandomPlayer>(p2), grules);
    // g1.startGame();
    // return 0;
    std::vector<std::pair<int,int>> pos;
    int x,y;
    for (int i=0; i < 5; i ++) {
        x = 0;
        y = i;
        pos.push_back(std::make_pair(x,y));
    }
    Map objmap1(5,5);
    Map objmap2(5,5);
    std::shared_ptr<Map> map1 = std::make_shared<Map>(objmap1);
    std::shared_ptr<Map> map2 = std::make_shared<Map>(objmap2);
    std::pair<std::shared_ptr<Map>, std::shared_ptr<Map>> maps1 = std::make_pair(map1, map2);
    std::pair<std::shared_ptr<Map>, std::shared_ptr<Map>> maps2 = std::make_pair(map2, map1);
   
    Ship s1({{1,1}, {1,2}});
    Player p1("Michał", maps1);
    Player p2("Maciek",maps2);
    p2.getMyMap().show();
    std::cout << std::endl;
    p2.createShip(pos);
    p2.getMyMap().show();
    std::cout << std::endl;
    p1.createShip(pos);
    p1.selectTarget(0,1);
    p2.getMyMap().show();
    std::cout <<std::endl;

    s1.shoot(0, 2, map1);
    p2.checkStatus();
    p2.getMyMap().show();

    std::cout << std::endl;

    p1.getMyMap().show();

}


