#include "WrongShootCoordinates.h"

WrongShootCoordinates::WrongShootCoordinates(const std::string &message)
    : std::runtime_error(message){};