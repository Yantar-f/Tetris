//
// Created by Yantar on 18/11/2023.
//

#include "FatalTerminationManager.h"
#include "Log/Logger.h"

void FatalTerminationManager::terminateApp(int statusCode) {
    LOG_FATAL("Program terminated");
    exit(statusCode);
}
