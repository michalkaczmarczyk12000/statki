#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include "Player.h"
#include "Map.h"






// Tests for the Player class
TEST_CASE("Player Tests", "[player]") {
    Map testmap2(5,5);
    Map testmap1(5, 5);
    std::shared_ptr<Map> map1 = std::make_shared<Map>(testmap1);
    std::shared_ptr<Map> map2 = std::make_shared<Map>(testmap2);
    maps maps1 = {
            std::make_pair(std::make_shared<Map>(testmap1), std::make_shared<Map>(testmap2))
    };

    maps maps2 = {
            std::make_pair(std::make_shared<Map>(testmap2), std::make_shared<Map>(testmap1))
    };
    SECTION("Get Rank") {

        Player player("John", maps1, 5);
        REQUIRE(player.getRank() == 5);
    }

    SECTION("Can Place Ship") {
        Player player("Alice", maps2, 3);
        REQUIRE(player.canPlaceShip() == true);
    }

    SECTION("Create Ship and Place on Map") {
        Player player("Bob", maps1, 7);
        std::vector<Coordinates> shipCoordinates = {{0, 0}, {0, 1}, {0, 2}};
        player.createShip(shipCoordinates);


        auto ships = player.getMyMap().getShips();
        REQUIRE(ships.size() == 1);


        auto shipCoords = ships[0].getPositionOnMap();
        REQUIRE(shipCoords.size() == shipCoordinates.size());

    }

}