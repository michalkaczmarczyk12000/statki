#pragma once

#include <stdexcept>

class CannotMoveToDestination : public std::runtime_error {
public:
  CannotMoveToDestination(const std::string &message);
};
