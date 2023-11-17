#include "Application.h"
#include "Logger.h"

int main() {
    Logger logger("main");
    logger.log_info("Running application");

    Application application;
    application.run();

    logger.log_info("Program finished");
}
