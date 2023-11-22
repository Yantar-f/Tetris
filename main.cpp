#include <memory>

#include "Application.h"
#include "Log/Logger.h"
#include "FatalTerminationManager.h"

std::unique_ptr<int> in() {
    return std::make_unique<int> (212);
}

int main() {
    LOG_INFO("Running application");
    std::vector<std::unique_ptr<int>> v;
    v.push_back(in());
    ++(*v[0]);
    LOG_INFO("point");
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
