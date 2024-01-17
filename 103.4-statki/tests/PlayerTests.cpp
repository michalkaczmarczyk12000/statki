#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include "Player.h"
#include "Map.h"


TEST_CASE("Player Tests", "[player]") {
    Map testmap2(5,5);
    Map testmap1(5, 5);
    std::shared_ptr<Map> map1 = std::make_shared<Map>(testmap1);
    std::shared_ptr<Map> map2 = std::make_shared<Map>(testmap2);
    maps maps1 = {
            std::make_pair(map1, map2)
    };

    maps maps2 = {
            std::make_pair(map2, map1)
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
    SECTION("Change Rank") {
        Player player("Charlie", maps2, 5);
        player.changeRank(10);
        REQUIRE(player.getRank() == 15);
    }

    SECTION("Select Target") {
        Player player("David", maps1, 5);
        Coordinates targetCoords = {3, 2};
        Ship s({targetCoords});

        maps1.maps.second->placeShip(s);
        maps1.maps.first->placeShip(s);
        player.selectTarget(targetCoords);

        REQUIRE(maps1.maps.second->getField(targetCoords)->getStatusToDisplay() == 'x');
    }

    SECTION("Update Status") {
        Player player("Eva", maps2, 5);

        player.updateStatus();

        auto shipStatus = player.getMyMap().getShips();

        REQUIRE(shipStatus.size() == 0);
    }

    SECTION("miss shoot") {
        Player player("Frank", maps1, 5);
        Coordinates shotCoords = {0 , 1};
        Ship s({Coordinates(0, 0)});

        maps1.maps.second->placeShip(s);
        maps1.maps.first->placeShip(s);
        player.selectTarget(shotCoords);

        REQUIRE(player.getEnemyMap().getField(shotCoords)->getStatusToDisplay() == 'm');
    }

}