#include "GameState.h"

GameState::GameState(StateStack& stateStack, Context context) : State(stateStack, context) {}

bool GameState::handleEvent(sf::Event) {
    return true;
}

bool GameState::update(TimePointMs) {
    return true;
}

bool GameState::draw() {
    return true;
}

bool GameState::isTransparent() {
    return true;
}
