#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include "Field.h"


TEST_CASE("Field Initialization") {
    Field field(Coordinates(1, 2), FieldStatus::zero, true);

    REQUIRE(field.getx() == 1);
    REQUIRE(field.gety() == 2);
    REQUIRE(field.getStatus() == FieldStatus::zero);
    REQUIRE(field.isHidden() == true);
}

TEST_CASE("Field Status Modification") {
    Field field(Coordinates(3, 4), FieldStatus::one, false);

    REQUIRE(field.getStatus() == FieldStatus::one);

    field.setStatus(FieldStatus::x);

    REQUIRE(field.getStatus() == FieldStatus::x);
}

TEST_CASE("Field Visibility Modification") {
    Field field(Coordinates(5, 6), FieldStatus::zero, true);

    REQUIRE(field.isHidden() == true);

    field.setHidden(false);

    REQUIRE(field.isHidden() == false);
}

TEST_CASE("Field Display Status") {
    Field field(Coordinates(7,  8), FieldStatus::miss, false);

    REQUIRE(field.getStatusToDisplay() == 'm');
}

TEST_CASE("Field Coordinates Modification") {
    Field field(Coordinates(9, 10), FieldStatus::zero, false);

    REQUIRE(field.getx() == 9);
    REQUIRE(field.gety() == 10);

    field.setx(11);
    field.sety(12);

    REQUIRE(field.getx() == 11);
    REQUIRE(field.gety() == 12);
}