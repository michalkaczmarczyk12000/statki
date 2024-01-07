
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
        std::cin >> x >> y;
        pos.push_back(std::make_pair(x,y));
    }
    Ship ship1(5,pos);
    std::shared_ptr<Ship> pship = std::make_shared<Ship>(ship1);
    testmap.placeShip(pship);
    std::cout << std::endl;
    testmap.show();

}


