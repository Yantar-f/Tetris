#ifndef TETRIS_FATALTERMINATIONMANAGER_HPP
#define TETRIS_FATALTERMINATIONMANAGER_HPP

#include "log/Logger.hpp"

#include <string>

class FatalTerminationManager {
public:
    static void terminateApp(int statusCode);
};

#define TERMINATE(statusCode) FatalTerminationManager::terminateApp(statusCode)

#endif //TETRIS_FATALTERMINATIONMANAGER_HPP
