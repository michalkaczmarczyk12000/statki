cmake_minimum_required(VERSION 3.16.0)
project(Statki VERSION 0.1.0)

add_library(Statki STATIC
    Field.cpp
    Map.cpp
    Ship.cpp
    Player.cpp
    RandomPlayer.cpp
    Game.cpp
    MapReader.cpp
    Writer.cpp
    GameRules.cpp
)

set_target_properties(Statki
    PROPERTIES 
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_compile_options(Statki PRIVATE -Wall -Wextra -pedantic )

