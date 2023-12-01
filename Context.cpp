#include "Context.hpp"
#include "log/Logger.hpp"
#include "FatalTerminationManager.hpp"

Context::Context(sf::VideoMode videoMode, const std::string& windowTitle, sf::Uint32 windowStyle, const char* resourcePath) :
        renderWindow(videoMode, windowTitle, windowStyle),
        resourcePath(resourcePath) {
    if (!mainFont.loadFromFile(this->resourcePath + "/fonts/arial.ttf")) {
        LOG_FATAL("Loading font error");
        TERMINATE(EXIT_FAILURE);
    }

    LOG_INFO(std::string("Window width: ").append(std::to_string(videoMode.width)));
    LOG_INFO(std::string("Window height: ").append(std::to_string(videoMode.height)));
    LOG_INFO(std::string("Resource path: ").append(resourcePath));
}
