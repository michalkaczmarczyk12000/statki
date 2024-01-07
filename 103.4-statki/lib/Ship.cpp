#include "Ship.h"
#include <stdexcept>
#include <iostream>
Ship::Ship(int size, std::vector<std::pair<int,int>> positionOnMap) : 
    id_(countOfShips), size_(size) {
        if(size != positionOnMap.size())
            //throw std::runtime_error("musi byc taka sama wielkosc statku co ilosc arg");
            std::cout << "zly rozmiar" << std::endl;
        for(auto pair : positionOnMap) {
            if(pair.first < 0 || pair.second < 0)
                //throw std::invalid_argument("poza mapa");
                std::cout << "poza mapa" << std::endl;
            positionOnMap_.push_back(Field(pair.first, pair.second, true));
        }
    countOfShips += 1;
    }

std::vector<Field> Ship::getPositionOnMap() {
    return positionOnMap_;
}

int Ship::countOfShips = 0;