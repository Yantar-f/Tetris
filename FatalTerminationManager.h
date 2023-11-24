#ifndef TETRIS_FATALTERMINATIONMANAGER_H
#define TETRIS_FATALTERMINATIONMANAGER_H

#include <string>
#include "Log/Logger.h"

class FatalTerminationManager {
public:
    static void terminateApp(int statusCode);
};

#define TERMINATE(statusCode) FatalTerminationManager::terminateApp(statusCode)
#define LOGGED_TERMINATE(statusCode, message) (LOG_FATAL(message), FatalTerminationManager::terminateApp(statusCode))

#endif //TETRIS_FATALTERMINATIONMANAGER_H
