
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
    std::vector<std::shared_ptr<Field>> poss = ship1.getPositionOnMap();
    std::cout << std::endl;
    for(auto f : poss) {
        std::cout << f->getStatusToDisplay() << "\t";
    }
    std::cout << std::endl << poss[poss.size()-1]->getStatusToDisplay() << std::endl;
    ship1.shoot(0, 3, testmap);

    testmap.show();
    ship1.updateShip();
    std::vector<std::shared_ptr<Field>> poss2 = ship1.getPositionOnMap();
    for(auto f2 : poss2) {
        std::cout << f2->getStatusToDisplay() << "\t";
    }
    std::cout << std::endl;
    testmap.showForEnemy();

    ship1.shoot(4,4,testmap);
    std::cout << std::endl;
    testmap.show();






}


