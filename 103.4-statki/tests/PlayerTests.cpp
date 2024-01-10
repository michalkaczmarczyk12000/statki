#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include "Player.h"
#include "Map.h"


TEST_CASE("Player rank initialization") {
    Player player("John", {Map(5, 5), Map(5, 5)}, 5);
    REQUIRE(player.getRank() == 5);
}

TEST_CASE("Player ship placement") {
    Player player("John", {Map(5, 5), Map(5, 5)}, 5);

    SECTION("Can place ship") {
        REQUIRE(player.canPlaceShip() == true);
    }

    SECTION("Place ship on the map") {
        std::vector<std::pair<int, int>> shipPositions = {{0, 0}, {0, 1}};
        player.createShip(shipPositions);
        REQUIRE(player.getMyMap().getShips().size() == 1);
    }
}

TEST_CASE("Player shooting at enemy map") {

    std::pair<Map, Map> maps = std::make_pair(Map(5, 5), Map(5, 5));
    Player player("Bob", maps, 8);
    player.createShip({{0, 0}, {0, 1}});
    REQUIRE_FALSE(!player.hasShips());
    SECTION("Select target and shoot") {
        // Assuming there is a ship on the enemy map
        player.getEnemyMap().placeShip(Ship({{0, 0}, {0, 1}}));
        player.selectTarget(0, 0, player.getEnemyMap());
        INFO("Actual status: " << player.getEnemyMap().getField(0, 0)->getStatusToDisplay());
        player.getEnemyMap().show();
        REQUIRE(static_cast<char>(player.getEnemyMap().getField(0, 0)->getStatus()) == static_cast<char>(FieldStatus::x));
    }

    SECTION("Check status after shooting") {
        Map enemyMap(10 ,10);
        enemyMap.placeShip(Ship({{0, 0}, {0, 1}}));
        player.selectTarget(0, 0, enemyMap);
        player.checkStatus();
        REQUIRE(player.hasShips() == true);
    }
}