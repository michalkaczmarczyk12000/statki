#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include "Player.h"
#include "Map.h"


TEST_CASE("Player rank initialization") {
    Map objmap1(5,5);
    Map objmap2(5,5);
    std::shared_ptr<Map> map1 = std::make_shared<Map>(objmap1);
    std::shared_ptr<Map> map2 = std::make_shared<Map>(objmap2);
    std::pair<std::shared_ptr<Map>, std::shared_ptr<Map>> maps1 = std::make_pair(map1, map2);
    Player player("John", maps1, 5);
    REQUIRE(player.getRank() == 5);
}

TEST_CASE("Player ship placement") {
    Map objmap1(5,5);
    Map objmap2(5,5);
    std::shared_ptr<Map> map1 = std::make_shared<Map>(objmap1);
    std::shared_ptr<Map> map2 = std::make_shared<Map>(objmap2);
    std::pair<std::shared_ptr<Map>, std::shared_ptr<Map>> maps1 = std::make_pair(map1, map2);
    Player player("John", maps1, 5);

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

    Map objmap1(5,5);
    Map objmap2(5,5);
    std::shared_ptr<Map> map1 = std::make_shared<Map>(objmap1);
    std::shared_ptr<Map> map2 = std::make_shared<Map>(objmap2);
    std::pair<std::shared_ptr<Map>, std::shared_ptr<Map>> maps1 = std::make_pair(map1, map2);
    std::pair<std::shared_ptr<Map>, std::shared_ptr<Map>> maps2 = std::make_pair(map2, map1);
    Player player1("Bob", maps1, 8);
    Player player2("John", maps2, 8);
    player1.createShip({{0, 0}, {0, 1}});
    REQUIRE_FALSE(!player1.hasShips());
    SECTION("Select target and shoot") {
        // Assuming there is a ship on the enemy map
        player2.createShip({{0, 0}, {0, 1}});
        player1.selectTarget(0, 0);
        INFO("Actual status: " << player1.getEnemyMap().getField(0, 0)->getStatusToDisplay());
        player1.getEnemyMap().show();
        REQUIRE(static_cast<char>(player1.getEnemyMap().getField(0, 0)->getStatus()) == static_cast<char>(FieldStatus::x));
    }

    SECTION("Check status after shooting") {
        player1.selectTarget(0, 1);
        player2.checkStatus();
        REQUIRE(player2.hasShips() == false);
    }
}