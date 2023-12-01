#include "FatalTerminationManager.hpp"

void FatalTerminationManager::terminateApp(int statusCode) {
    LOG_FATAL("Program terminated");
    exit(statusCode);
}
