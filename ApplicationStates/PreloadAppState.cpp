#include "PreloadAppState.h"

PreloadAppState::PreloadAppState(StateStack& stackStack) : State(stackStack) {}

bool PreloadAppState::handleEvent(sf::Event) {
    return true;
}

bool PreloadAppState::update(TimePointMs) {
    return true;
}

bool PreloadAppState::draw() {
    return true;
}

