#include "Map.h"
#include <string>

class MapReader {
private:
    std::string filename_;
public:
    MapReader() = default;
    Map createMap(std::string filename);
    std::vector<std::vector<char>> readMap(std::string filename);
//    std::vector<std::vector<char>> readMapMatrix();
    std::vector<std::string> readMapMatrixstr(std::string filename);
};