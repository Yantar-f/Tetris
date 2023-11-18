#include "Application.h"
#include "Logger.h"
#include "FatalTerminationManager.h"

int main() {
    LOG_INFO("Running application");

    try {
        Application application;
        application.run();
    } catch (std::exception& ex) {
        LOG_FATAL(std::string("Undefined exception: ").append(ex.what()));
        FatalTerminationManager::terminateApp(1);
    }

    LOG_INFO("Program finished");
    return 0;
}
