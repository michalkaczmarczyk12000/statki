#include "Map.h"
#include <string>

class MapReader {
private:
    std::string filename_;
public:
    MapReader(std::string filename = "map.txt");
    std::vector<std::vector<char>> readMapMatrix();
    std::vector<std::string> readMapMatrixstr();
};