#include "Ship.h"
#include <stdexcept>
#include <iostream>
#include <algorithm>
Ship::Ship(std::vector<Coordinates> positionOnMap) :
    id_(countOfShips), size_(positionOnMap.size()) {
        // if(size != positionOnMap.size())
        //     //throw std::runtime_error("musi byc taka sama wielkosc statku co ilosc arg");
        //     std::cout << "zly rozmiar" << std::endl;
        for(auto pair : positionOnMap) {
            // if(pair.first < 0 || pair.second < 0)
            //     //throw std::invalid_argument("poza mapa");
            //     std::cout << "poza mapa" << std::endl;
            positionOnMap_.push_back(std::make_shared<Field>(Coordinates(pair.x, pair.y), FieldStatus::one));
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
    positionOnMap_.erase(
            std::remove_if(
                    positionOnMap_.begin(),
                    positionOnMap_.end(),
                    [](const std::shared_ptr<Field>& field) {
                        return field->getStatus() == FieldStatus::x;
                    }
            ),
            positionOnMap_.end()
    );
}

void Ship::move(Coordinates coords, orientation shipOrientation) {
    if(size_ != positionOnMap_.size()) {
        //tu cos w przyszlosc
        std::cout << "cant move damaged ship" << std::endl;
        return;
    }
    positionOnMap_ = predictNewPosition(coords, shipOrientation);
}

std::vector<std::shared_ptr<Field>> Ship::predictNewPosition(Coordinates coords, orientation shipOrientation) {
    int currentX = coords.x;
    int currentY = coords.y;
    std::vector<std::shared_ptr<Field>> newPosition;
    for (int i = 0; i < size_; ++i) {
        newPosition.push_back(std::make_shared<Field>(Coordinates(currentX, currentY), FieldStatus::one));
        if (shipOrientation == orientation::horizontally) {
            ++currentY;
        } else {
            ++currentX;
        }
    }
    return newPosition;
}



int Ship::countOfShips = 0;