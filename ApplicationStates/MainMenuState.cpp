#include "MainMenuState.h"

MainMenuState::MainMenuState(StateStack& stateStack) : State(stateStack) {}

bool MainMenuState::handleEvent(sf::Event) {
    return true;
}

bool MainMenuState::update(TimePointMs) {
    return true;
}

bool MainMenuState::draw() {
    return true;
}
