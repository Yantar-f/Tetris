#include "GameState.hpp"
#include "../exceptions/NoSpawnSpaceException.hpp"

GameState::GameState(StateStack& stateStack, Context& context) :
        State(stateStack, context),
        field(new bool*[DEFAULT_FIELD_WIDTH]) {

    cellShape.setFillColor(sf::Color::Yellow);
    cellShape.setSize({DEFAULT_CELL_SIZE, DEFAULT_CELL_SIZE});

    boxShape.setFillColor(sf::Color::Cyan);
    boxShape.setSize({DEFAULT_CELL_SIZE, DEFAULT_CELL_SIZE});

    for (int column = 0; column < DEFAULT_FIELD_WIDTH; ++column) {
        field[column] = new bool[DEFAULT_FIELD_HEIGHT];

        for (int row = 0; row < DEFAULT_FIELD_HEIGHT; ++row) {
            field[column][row] = false;
        }
    }
}

bool GameState::handleEvent(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::Escape: {
                stateStack.pushState(StateName::GamePause);
                break;
            }

            case sf::Keyboard::R: {
                isRotating = true;
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
        if ( ! trySpawnShape()) {
            stateStack.pushState(StateName::EndGame);
            return true;
        }

        verticalMovingTick = timePoint;
        isStabled = false;
    }

    if (timePoint - horizontalMovingTick > horizontalMovingTickDuration) {
        if (isMovingLeft) {
            isMovingLeft = false;
            playerShape->moveLeft();
        }

        if (isMovingRight) {
            isMovingRight = false;
            playerShape->moveRight();
        }

        if (isRotating) {
            isRotating = false;
            playerShape->rotate();
        }

        horizontalMovingTick = timePoint;
    }

    if (timePoint - verticalMovingTick > verticalMovingTickDuration) {
        if ( ! playerShape->moveDown()) {
            isStabled = true;
        }

        verticalMovingTick = timePoint;
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

bool GameState::trySpawnShape() {
    try {
        playerShape = TetrisShape::createShape(
                static_cast<ShapeType>(shapeTypeRange(randEngine)),
                field,
                DEFAULT_FIELD_WIDTH,
                DEFAULT_FIELD_HEIGHT);
    } catch (NoSpawnSpaceException& ex) {
        LOG_INFO("No space to spawn tetris shape");
        return false;
    }

    return true;
}

GameState::~GameState() {
    if (field != nullptr) {
        for (int i = 0; i < DEFAULT_FIELD_WIDTH; ++i) delete field[i];
        delete[] field;
    }
}
