#include "Application.h"
#include "Logger.h"

int main() {
    LOG_INFO("Running application");

    try {
        Application application;
        application.run();
    } catch (std::exception& exception) {
        LOG_FATAL(exception.what());
        LOG_FATAL("Program terminated");
        return 1;
    }

    LOG_INFO("Program finished");
}
