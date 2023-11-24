#include "FatalTerminationManager.h"

void FatalTerminationManager::terminateApp(int statusCode) {
    LOG_FATAL("Program terminated");
    exit(statusCode);
}
