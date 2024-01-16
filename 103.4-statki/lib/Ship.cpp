#include "Ship.h"
#include <stdexcept>
#include <iostream>
Ship::Ship(std::vector<Coordinates> positionOnMap) :
    id_(countOfShips), size_(positionOnMap.size()) {
        // if(size != positionOnMap.size())
        //     //throw std::runtime_error("musi byc taka sama wielkosc statku co ilosc arg");
        //     std::cout << "zly rozmiar" << std::endl;
        for(auto pair : positionOnMap) {
            // if(pair.first < 0 || pair.second < 0)
            //     //throw std::invalid_argument("poza mapa");
            //     std::cout << "poza mapa" << std::endl;
            positionOnMap_.push_back(std::make_shared<Field>(pair.x, pair.y, FieldStatus::one));
        }
    countOfShips += 1;
    }

std::vector<std::shared_ptr<Field>> Ship::getPositionOnMap() const {
    return positionOnMap_;
}


void Ship::shoot(Coordinates c, std::shared_ptr<Map> map) {
    std::shared_ptr<Field> PHitField = map->getField(c);
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