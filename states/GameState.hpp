#ifndef TETRIS_GAMESTATE_HPP
#define TETRIS_GAMESTATE_HPP

#include "State.hpp"

using namespace std::chrono_literals;

#define DEFAULT_FIELD_WIDTH 10
#define DEFAULT_FIELD_HEIGHT 12
#define DEFAULT_CELL_SIZE 40

class GameState : public State {
public:
    GameState(StateStack &stateStack, Context& context);

    bool handleEvent(sf::Event) override;
    bool update(TimePointMs) override;
    bool draw() override;
    bool isTransparent() override;

private:
    bool tryGenerateShape();
    bool isShapeColliding();

private:
    bool field[DEFAULT_FIELD_WIDTH][DEFAULT_FIELD_HEIGHT] {};
    bool isStabled { true };
    bool isMovingLeft { false };
    bool isMovingRight { false };
    std::chrono::milliseconds horizontalMovingTickDuration { 5ms };
    std::chrono::milliseconds verticalMovingTickDuration { 20ms };
    TimePointMs horizontalMovingTick { TIME_POINT };
    TimePointMs verticalMovingTick { TIME_POINT };
    sf::RectangleShape boxShape;
    sf::RectangleShape cellShape;
    sf::Vector2i shapeTilesPoss[4];
};


#endif //TETRIS_GAMESTATE_HPP
