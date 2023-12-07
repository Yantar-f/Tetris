#include "GameState.hpp"

GameState::GameState(StateStack& stateStack, Context& context) : State(stateStack, context) {
    cellShape.setFillColor(sf::Color::Yellow);
    cellShape.setSize({DEFAULT_CELL_SIZE, DEFAULT_CELL_SIZE});

    boxShape.setFillColor(sf::Color::Cyan);
    boxShape.setSize({DEFAULT_CELL_SIZE, DEFAULT_CELL_SIZE});
}

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
    for (int column = 0; column < DEFAULT_FIELD_WIDTH; ++column) {
        for (int row = 0; row < DEFAULT_FIELD_HEIGHT; ++row) {
            if (field[column][row]) {
                boxShape.setPosition(
                    static_cast<float>(column)*DEFAULT_CELL_SIZE,
                    static_cast<float>(row)*DEFAULT_CELL_SIZE);

                context.renderWindow.draw(boxShape);
            } else {
                cellShape.setPosition(
                    static_cast<float>(column)*DEFAULT_CELL_SIZE,
                    static_cast<float>(row)*DEFAULT_CELL_SIZE);

                context.renderWindow.draw(cellShape);
            }
        }
    }
    return true;
}

bool GameState::isTransparent() {
    return true;
}
