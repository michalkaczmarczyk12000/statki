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
            positionOnMap_.push_back(std::make_shared<Field>(pair.first, pair.second, FieldStatus::one));
        }
    countOfShips += 1;
    }

std::vector<std::shared_ptr<Field>> Ship::getPositionOnMap() const {
    return positionOnMap_;
}

//do kolejnego etapu

void Ship::shoot(int x, int y, Map map) {
    std::shared_ptr<Field> PHitField = map.getField(x,y);
    if (PHitField->getStatus() == FieldStatus::one) {
    PHitField->setStatus(FieldStatus::x);}
    else{
        PHitField->setStatus(FieldStatus::miss);
    }
    PHitField->setHidden(false);
}

void Ship::updateShip() {
    for (auto it = positionOnMap_.begin(); it != positionOnMap_.end();) {
        if ((*it)->getStatus() == FieldStatus::x) {
            it = positionOnMap_.erase(it);
        } else {
            ++it;
        }
    }
}

int Ship::countOfShips = 0;