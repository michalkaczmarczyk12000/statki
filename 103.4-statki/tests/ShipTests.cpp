#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include "Ship.h"
#include <algorithm>

TEST_CASE("Ship initialization and position retrieval", "[Ship]") {

    std::vector<Coordinates> shipPositions = {Coordinates(1, 1), Coordinates(1, 2), Coordinates(1, 3)};
    Ship ship(shipPositions);

    REQUIRE(ship.getPositionOnMap().size() == 3);


    REQUIRE(std::find_if(ship.getPositionOnMap().begin(), ship.getPositionOnMap().end(),
                         [](const std::shared_ptr<Field>& field) {
                             return field->getx() == 1 && field->gety() == 1;
                         }) != ship.getPositionOnMap().end());

    REQUIRE(std::find_if(ship.getPositionOnMap().begin(), ship.getPositionOnMap().end(),
                         [](const std::shared_ptr<Field>& field) {
                             return field->getx() == 1 && field->gety() == 2;
                         }) != ship.getPositionOnMap().end());

    REQUIRE(std::find_if(ship.getPositionOnMap().begin(), ship.getPositionOnMap().end(),
                         [](const std::shared_ptr<Field>& field) {
                             return field->getx() == 1 && field->gety() == 3;
                         }) != ship.getPositionOnMap().end());
}



TEST_CASE("Ship shooting and updating", "[Ship]") {

    std::vector<Coordinates> shipPositions = {Coordinates(2, 2), Coordinates(2, 3)};
    Ship ship(shipPositions);
    std::shared_ptr<Map> map = std::make_shared<Map>(5, 5);
    map->placeShip(ship);

    ship.shoot(Coordinates(2, 2), map);

    REQUIRE(map->getField(Coordinates(2, 2))->getStatus() == FieldStatus::x);
    REQUIRE(map->getField(Coordinates(2, 2))->isHidden() == false);
    ship.updateShip();
    REQUIRE(ship.getPositionOnMap().size() == 1);
}

TEST_CASE("Ship movement", "[Ship]") {

    std::vector<Coordinates> shipPositions = {Coordinates(3, 3), Coordinates(3, 4), Coordinates(3, 5)};
    Ship ship(shipPositions);

    SECTION("Move ship horizontally") {

        ship.move(Coordinates(3,3), orientation::horizontally);


        REQUIRE(ship.getPositionOnMap()[0]->getx() == 3);
        REQUIRE(ship.getPositionOnMap()[0]->gety() == 3);
        REQUIRE(ship.getPositionOnMap()[1]->getx() == 3);
        REQUIRE(ship.getPositionOnMap()[1]->gety() == 4);
        REQUIRE(ship.getPositionOnMap()[2]->getx() == 3);
        REQUIRE(ship.getPositionOnMap()[2]->gety() == 5);
    }

    SECTION("Move ship vertically") {

        ship.move(Coordinates(3,3), orientation::vertically);


        REQUIRE(ship.getPositionOnMap()[0]->getx() == 3);
        REQUIRE(ship.getPositionOnMap()[0]->gety() == 3);
        REQUIRE(ship.getPositionOnMap()[1]->getx() == 4);
        REQUIRE(ship.getPositionOnMap()[1]->gety() == 3);
        REQUIRE(ship.getPositionOnMap()[2]->getx() == 5);
        REQUIRE(ship.getPositionOnMap()[2]->gety() == 3);
    }
}