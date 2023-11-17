#include "Application.h"
#include "Logger.h"

int main() {
    Logger logger("main");
    logger.log_info("Running application");

    try {
        Application application;
        application.run();
    } catch (std::exception& exception) {
        logger.log_fatal(exception.what());
        logger.log_fatal("Program terminated");
        return 1;
    }

    logger.log_info("Program finished");
}
