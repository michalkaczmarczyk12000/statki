#pragma once

#include <stdexcept>

class WrongShootCoordinates : public std::runtime_error {
public:
  WrongShootCoordinates(const std::string &message);
};