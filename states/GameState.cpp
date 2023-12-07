#include "GameState.hpp"

GameState::GameState(StateStack& stateStack, Context& context) : State(stateStack, context) {
    cellShape.setFillColor(sf::Color::Yellow);
    cellShape.setSize({DEFAULT_CELL_SIZE, DEFAULT_CELL_SIZE});

    boxShape.setFillColor(sf::Color::Cyan);
    boxShape.setSize({DEFAULT_CELL_SIZE, DEFAULT_CELL_SIZE});
}

bool GameState::handleEvent(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::Escape: {
                stateStack.pushState(StateName::GamePause);
                break;
            }

            case sf::Keyboard::R: {
                /*ROTATE*/
                break;
            }

            case sf::Keyboard::Left: {
                isMovingLeft = true;
                break;
            }

            case sf::Keyboard::Right: {
                isMovingRight = true;
                break;
            }

            default:;
        }
    } else if (event.type == sf::Event::KeyReleased) {
        switch (event.key.code) {
            case sf::Keyboard::Left:
            case sf::Keyboard::Right: {
                horizontalMovingTick -= horizontalMovingTickDuration;
                break;
            }

            default:;
        }
    }
    return true;
}

bool GameState::update(TimePointMs timePoint) {
    if (isStabled) {
        if ( ! tryGenerateShape()) {
            stateStack.pushState(StateName::EndGame);
            return true;
        }
    }

    if (isMovingLeft) {
        isMovingLeft = false;
        /*TRY MOVE RIGHT*/
    }

    if (isMovingRight) {
        isMovingRight = false;
        /*TRY MOVE RIGHT*/
    }

    if (isShapeColliding()) {
        isStabled = true;
    }

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

bool GameState::tryGenerateShape() {
    return true;
}

bool GameState::isShapeColliding() {
    for (sf::Vector2i tilePos : shapeTilesPoss) {
        sf::Vector2i comparablePos {tilePos.x, tilePos.y + 1};

        if (comparablePos.y == DEFAULT_FIELD_HEIGHT) return true;

        if (field[comparablePos.x][comparablePos.y]) {
            for (sf::Vector2 selfTilePos : shapeTilesPoss) {
                if (comparablePos == selfTilePos) return false;
            }

            return true;
        }
    }

    return false;
}
