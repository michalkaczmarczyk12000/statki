#include "CannotMoveToDestination.h"

CannotMoveToDestination::CannotMoveToDestination(const std::string &message)
    : std::runtime_error(message){};