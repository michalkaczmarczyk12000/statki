#include "MapReader.h"
#include <iostream>
#include <fstream>
#include <sstream>

Map MapReader::createMap(std::string filename) {
    readMap(filename);
    // tutaj logika wpisywnaia statków w funkcji, znajdź 1 i ich indeksy wtedy utwórz ship

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

std::vector<std::string> MapReader::readMapMatrixstr(std::string filename) {
    std::ifstream file(filename);
    if (!file.is_open())
        std::cout << "blad pliku2" << std::endl;
        //tu jakis wyjatek wlasny bedzie
    std::vector<std::string> map;
    std::string line;
    while(std::getline(file,line)){
//        std::getline(file, line);
        map.push_back(line);
    }
    return map;
}
