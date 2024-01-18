#pragma once

#include <stdexcept>

class CannotOpenFileError : public std::runtime_error {
public:
  CannotOpenFileError(const std::string &message);
};