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
//    std::vector<std::string> readMapMatrixstr(std::string filename);
    void placeShips(std::vector<std::vector<char>>& map, Map& gameMap);
    void findShipPositions(int startRow, int startCol, const std::vector<std::vector<char>>& map, std::vector<Coordinates>& shipPositions);
    bool isValidPosition(int row, int col, std::vector<std::vector<char>> map) const;
};