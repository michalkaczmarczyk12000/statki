#include "Ship.h"
#include <stdexcept>
#include <iostream>
#include <algorithm>
Ship::Ship(std::vector<Coordinates> positionOnMap) :
    id_(countOfShips), size_(positionOnMap.size()) {
        for(auto pair : positionOnMap) {
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

void Ship::move(int x, int y, orientation shipOrientation) {
    auto oldPosition = positionOnMap_;
    positionOnMap_.clear();
    int currentX = x;
    int currentY = y;
    for (int i = 0; i < size_; ++i) {
        positionOnMap_.push_back(std::make_shared<Field>(Coordinates(currentX, currentY), FieldStatus::one));
        if (shipOrientation == orientation::horizontally) {
            ++currentY;
        } else {
            ++currentX;
        }
    }

    for (auto field : positionOnMap_) {
        field->setHidden(false);
    }
}

int Ship::countOfShips = 0;