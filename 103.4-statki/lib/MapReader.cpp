#include "MapReader.h"
#include <iostream>
#include <fstream>
#include <sstream>

MapReader::MapReader(std::string filename) : filename_(filename){}

std::vector<std::vector<char>> MapReader::readMapMatrix() {
    std::ifstream file(filename_);
    if (!file.is_open())
        std::cout << "blad pliku" << std::endl;
        //tu jakis wyjatek wlasny bedzie
    std::vector<std::vector<char>> map;
    std::vector<char> row;
    std::string line;
    while(std::getline(file,line)){
//        std::getline(file, line);
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

std::vector<std::string> MapReader::readMapMatrixstr() {
    std::ifstream file(filename_);
    if (!file.is_open())
        std::cout << "blad pliku" << std::endl;
        //tu jakis wyjatek wlasny bedzie
    std::vector<std::string> map;
    std::string line;
    while(std::getline(file,line)){
//        std::getline(file, line);
        map.push_back(line);
    }
    return map;
}
