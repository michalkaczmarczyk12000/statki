
#include <iostream>
#include <vector>
#include <memory>
#include "../lib/Field.h"
#include "../lib/Map.h"
#include "../lib/Ship.h"


int main()
{
    std::cout << "Witaj w symulatorze gry w statki ver 1.0\n";
    Map testmap(5,5);
    testmap.show();
    int x,y;
    std::vector<std::pair<int,int>> pos;
    for (int i=0; i < 5; i ++) {
        //std::cin >> x >> y;
        x = 0;
        y = i;
        pos.push_back(std::make_pair(x,y));
    }
    Ship ship1(5,pos);  
    testmap.placeShip(ship1);
    std::cout << std::endl;
    testmap.show();
    std::cout << std::endl;
    testmap.showForEnemy();

    //tescik 
    testmap.ShipHit(false, 0, 4);
    std::vector<std::shared_ptr<Field>> poss = ship1.getPositionOnMap();
    std::cout << std::endl;
    for(auto f : poss) {
        std::cout << f->isTakenByShip() << "\t";
    }
    std::cout << std::endl << poss[poss.size()-1]->isTakenByShip() << std::endl;

    testmap.show();






}


