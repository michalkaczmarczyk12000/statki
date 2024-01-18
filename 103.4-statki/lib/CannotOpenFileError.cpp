#include "CannotOpenFileError.h"

CannotOpenFileError::CannotOpenFileError(const std::string &message)
    : std::runtime_error(message){};