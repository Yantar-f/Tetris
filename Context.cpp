#include "Context.h"
#include "log/Logger.h"

Context::Context(sf::VideoMode videoMode, const std::string& windowTitle, sf::Uint32 windowStyle, const char* resourcePath) :
        renderWindow(videoMode, windowTitle, windowStyle),
        resourcePath(resourcePath) {
    LOG_INFO(std::string("Window width: ").append(std::to_string(videoMode.width)));
    LOG_INFO(std::string("Window height: ").append(std::to_string(videoMode.height)));
    LOG_INFO(std::string("Resource path: ").append(resourcePath));
}
