#pragma once
#include "Field.h"
#include <vector>
class Map {
private:
    std::vector<std::vector<Field>> fields_;
public:
    Map(std::vector<std::vector<Field>> fields);
};