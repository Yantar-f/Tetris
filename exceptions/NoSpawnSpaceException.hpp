//
// Created by Yantar on 08/12/2023.
//

#ifndef TETRIS_NOSPAWNSPACEEXCEPTION_HPP
#define TETRIS_NOSPAWNSPACEEXCEPTION_HPP


#include <stdexcept>

class NoSpawnSpaceException : public std::runtime_error {
public:
    NoSpawnSpaceException();
};


#endif //TETRIS_NOSPAWNSPACEEXCEPTION_HPP
