//
// Created by Yantar on 08/12/2023.
//

#include "NoSpawnSpaceException.hpp"

NoSpawnSpaceException::NoSpawnSpaceException() : std::runtime_error("No space to spawn tetris shape") {}
