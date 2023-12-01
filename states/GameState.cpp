#include "GameState.hpp"

GameState::GameState(StateStack& stateStack, Context& context) : State(stateStack, context) {}

bool GameState::handleEvent(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape) {
            stateStack.pushState(StateName::GamePause);
        }
    }
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
