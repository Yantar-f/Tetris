#include "Context.h"

Context::Context(
    sf::VideoMode videoMode,
    const sf::String& windowTitle,
    sf::Uint32 windowStyle
) :
    renderWindow(videoMode, windowTitle, windowStyle) {}
