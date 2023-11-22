#include "PreloadAppState.h"

PreloadAppState::PreloadAppState(StateStack& stackStack, Context context) : State(stackStack, context) {}

bool PreloadAppState::handleEvent(sf::Event) {
    return true;
}

bool PreloadAppState::update(TimePointMs) {
    return true;
}

bool PreloadAppState::draw() {
    return true;
}

bool PreloadAppState::isTransparent() {
    return true;
}
