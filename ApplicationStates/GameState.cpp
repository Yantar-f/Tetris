#include "GameState.h"

GameState::GameState(StateStack& stateStack) : State(stateStack) {}

bool GameState::handleEvent(sf::Event) {
    return true;
}

bool GameState::update(TimePointMs) {
    return true;
}

bool GameState::draw() {
    return true;
}
