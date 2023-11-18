//
// Created by Yantar on 18/11/2023.
//

#include "FatalTerminationManager.h"
#include "Logger.h"

void FatalTerminationManager::terminateApp(const std::string& message, int statusCode) {
    LOG_FATAL(message);
    return terminateApp(statusCode);
}

void FatalTerminationManager::terminateApp(int statusCode) {
    LOG_FATAL("Program terminated");
    exit(statusCode);
}
