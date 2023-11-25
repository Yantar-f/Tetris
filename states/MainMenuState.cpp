#include <iostream>
#include "MainMenuState.h"

MainMenuState::MainMenuState(StateStack& stateStack, Context& context) : State(stateStack, context) {}

bool MainMenuState::handleEvent(sf::Event) {
    return true;
}

bool MainMenuState::update(TimePointMs) {
    return true;
}

bool MainMenuState::draw() {
    return true;
}

bool MainMenuState::isTransparent() {
    return true;
}
