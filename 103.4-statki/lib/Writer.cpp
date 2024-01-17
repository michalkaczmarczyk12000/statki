#include <iostream>
#include <fstream>
#include "Map.h"
#include "Writer.h"



void Writer::writeMapToFile(const Map& map, const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening the file for writing: " << filename << std::endl;
        return;
    }

    for (int i = 0; i < map.getSizeX(); ++i) {
        for (int j = 0; j < map.getSizeY(); ++j) {
        auto field = map.getField(Coordinates(i, j));
            file << field->getStatusToDisplay() << ' ';
        }
        file << '\n';
    }

    std::cout << "Map has been successfully written to file: " << filename << std::endl;
}
