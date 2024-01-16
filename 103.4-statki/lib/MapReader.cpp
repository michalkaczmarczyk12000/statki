#include "MapReader.h"
#include <iostream>
#include <fstream>
#include <sstream>


void MapReader::placeShips(std::vector<std::vector<char>>& map, Map& gameMap) {
    for (size_t i = 0; i < map.size(); ++i) {
        for (size_t j = 0; j < map[i].size(); ++j) {
            if (map[i][j] == '1') {
                std::vector<std::pair<int, int>> shipPositions;
                findShipPositions(i, j, map,shipPositions);

                if (!shipPositions.empty()) {
                    Ship ship(shipPositions);
                    gameMap.placeShip(ship);
                }
            }
        }
    }
}

void MapReader::findShipPositions(int startRow, int startCol, const std::vector<std::vector<char>>& map, std::vector<std::pair<int, int>>& shipPositions) {
    if (isValidPosition(startRow, startCol, map) && map[startRow][startCol] == '1') {
        shipPositions.push_back(std::make_pair(startRow, startCol));

        const_cast<std::vector<std::vector<char>>&>(map)[startRow][startCol] = '0';

        findShipPositions(startRow + 1, startCol, map, shipPositions);
        findShipPositions(startRow - 1, startCol, map, shipPositions);
        findShipPositions(startRow, startCol + 1, map, shipPositions);
        findShipPositions(startRow, startCol - 1, map, shipPositions);
    }
}


bool MapReader::isValidPosition(int row, int col, std::vector<std::vector<char>> map) const {
    return row >= 0 && row < map.size() && col >= 0 && col < map[row].size();
}

Map MapReader::createMap(std::string filename) {
    auto mapData = readMap(filename);
    Map mapFromFile(mapData.size(), mapData[0].size());
    placeShips(mapData, mapFromFile);
    return mapFromFile;
}


std::vector<std::vector<char>> MapReader::readMap(std::string filename) {
    std::ifstream file(filename);
    if (!file.is_open())
        std::cout << "blad pliku" << std::endl;
    std::vector<std::vector<char>> map;
    std::vector<char> row;
    std::string line;
    while(std::getline(file,line)){
        std::istringstream iss(line);
        row = {};
        char c;
        while(iss >> c) {

            row.push_back(c);
        }
        map.push_back(row);
    }
    return map;
}

//std::vector<std::string> MapReader::readMapMatrixstr(std::string filename) {
//    std::ifstream file(filename);
//    if (!file.is_open())
//        std::cout << "blad pliku2" << std::endl;
//        //tu jakis wyjatek wlasny bedzie
//    std::vector<std::string> map;
//    std::string line;
//    while(std::getline(file,line)){
////        std::getline(file, line);
//        map.push_back(line);
//    }
//    return map;
//}
