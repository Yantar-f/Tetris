#ifndef TETRIS_FATALTERMINATIONMANAGER_H
#define TETRIS_FATALTERMINATIONMANAGER_H

#include <string>
#include "log/Logger.h"

class FatalTerminationManager {
public:
    static void terminateApp(int statusCode);
};

#define TERMINATE(statusCode) FatalTerminationManager::terminateApp(statusCode)

#endif //TETRIS_FATALTERMINATIONMANAGER_H
