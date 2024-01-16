//
// Created by michal on 16.01.24.
//

#ifndef STATKI_WRITER_H
#define STATKI_WRITER_H
#include "Map.h"

class Writer {
public:
    Writer() = default;
    void writeMapToFile(const Map& map, const std::string& filename) const;
};




#endif //STATKI_WRITER_H
