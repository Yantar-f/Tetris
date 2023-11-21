#include "GamePauseState.h"

GamePauseState::GamePauseState(StateStack& stateStack, Context context) : State(stateStack, context) {}

bool GamePauseState::handleEvent(sf::Event) {
    return true;
}

bool GamePauseState::update(TimePointMs) {
    return true;
}

bool GamePauseState::draw() {
    return true;
}
