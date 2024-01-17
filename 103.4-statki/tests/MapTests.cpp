#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include "Map.h"
#include "Ship.h"

TEST_CASE("Map Initialization") {

Map emptyMap(5, 5, {});

REQUIRE(emptyMap.getSizeX() == 5);
REQUIRE(emptyMap.getSizeY() == 5);
REQUIRE(emptyMap.getShips().empty());
}

TEST_CASE("Map Initialization with Ships") {
std::vector<Ship> ships;
Ship s1({{1,1}});
Ship s2({{2,2}});
ships.push_back(s1);
ships.push_back(s2);  // Add s2 to the vector of ships
Map mapWithShips(8, 8, ships);

REQUIRE(mapWithShips.getSizeX() == 8);
REQUIRE(mapWithShips.getSizeY() == 8);
REQUIRE(mapWithShips.getShips().size() == 2);
}

TEST_CASE("Map Ship Placement") {
Map map(6, 6, {});
Ship ship({{3,0}});
map.placeShip(ship);

REQUIRE(map.getShips().size() == 1);
REQUIRE(map.getField(Coordinates(0, 0))->getStatusToDisplay() == '0');
REQUIRE(map.getField(Coordinates(1, 0))->getStatusToDisplay() == '0');
REQUIRE(map.getField(Coordinates(2, 0))->getStatusToDisplay() == '0');
}

TEST_CASE("Map Ship Movement") {
Map map(6, 6, {});
Ship ship({{2,0}});
map.placeShip(ship);

REQUIRE(map.getField(Coordinates(0, 0))->getStatusToDisplay() == '0');
REQUIRE(map.getField(Coordinates(1, 0))->getStatusToDisplay() == '0');
REQUIRE(map.getField(Coordinates(2, 0))->getStatusToDisplay() == '1');

map.moveShip(0, 0, 2, orientation::horizontally);

REQUIRE(map.getField(Coordinates(0, 0))->getStatusToDisplay() == '0');
REQUIRE(map.getField(Coordinates(1, 0))->getStatusToDisplay() == '0');
REQUIRE(map.getField(Coordinates(2, 0))->getStatusToDisplay() == '0');
REQUIRE(map.getField(Coordinates(0, 2))->getStatusToDisplay() == '1');
REQUIRE(map.getField(Coordinates(1, 2))->getStatusToDisplay() == '0');
REQUIRE(map.getField(Coordinates(2, 2))->getStatusToDisplay() == '0');
}

TEST_CASE("Map Visibility for Enemy") {
Map map(4, 4, {});
Ship ship({{2,0}});
map.placeShip(ship);

for (int i = 0; i < map.getSizeX(); ++i) {
    for (int j = 0; j < map.getSizeY(); ++j) {
        REQUIRE(map.getField(Coordinates(i, j))->isHidden() == true);
        }
    }
}
