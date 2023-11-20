#include "GamePauseState.h"

GamePauseState::GamePauseState(StateStack& stateStack) : State(stateStack) {}

bool GamePauseState::handleEvent(sf::Event) {
    return true;
}

bool GamePauseState::update(TimePointMs) {
    return true;
}

bool GamePauseState::draw() {
    return true;
}
