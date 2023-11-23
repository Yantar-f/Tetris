#include "Application.h"
#include "FatalTerminationManager.h"

int main() {
    LOG_INFO("Running application");

    try {
        Application application;
        application.run();
    } catch (std::exception& ex) {
        LOG_FATAL(std::string("Undefined exception: ").append(ex.what()));
        TERMINATE(EXIT_FAILURE);
    }

    LOG_INFO("Application finished");
    return 0;
}
