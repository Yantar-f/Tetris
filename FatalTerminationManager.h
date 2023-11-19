//
// Created by Yantar on 18/11/2023.
//

#ifndef TETRIS_FATALTERMINATIONMANAGER_H
#define TETRIS_FATALTERMINATIONMANAGER_H

#pragma once
#include <string>
#include "Log/Logger.h"

class FatalTerminationManager {
public:
    static void terminateApp(int statusCode);
};

#define TERMINATE(statusCode) FatalTerminationManager::terminateApp(statusCode)
#define TERMINATE_M(statusCode, message) (LOG_FATAL(message), FatalTerminationManager::terminateApp(statusCode))

#endif //TETRIS_FATALTERMINATIONMANAGER_H
