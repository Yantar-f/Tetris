#ifndef TETRIS_GAMESTATE_HPP
#define TETRIS_GAMESTATE_HPP

#include <random>
#include "State.hpp"

using namespace std::chrono_literals;

#define MIN_FIELD_WIDTH 4
#define MIN_FIELD_HEIGHT 4
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
    bool trySpawnShape();
    bool isShapeColliding();

private:
    bool field[DEFAULT_FIELD_WIDTH][DEFAULT_FIELD_HEIGHT] {};
    bool isStabled { true };
    bool isMovingLeft { false };
    bool isMovingRight { false };
    TimePointMs horizontalMovingTick { TIME_POINT };
    TimePointMs verticalMovingTick { TIME_POINT };
    std::chrono::milliseconds horizontalMovingTickDuration { 5ms };
    std::chrono::milliseconds verticalMovingTickDuration { 500ms };
    sf::RectangleShape boxShape;
    sf::RectangleShape cellShape;
    sf::Vector2i shapeTilesPoss[4];
    std::minstd_rand randEngine { static_cast<unsigned int>(TIME_POINT.time_since_epoch().count()) };
    std::uniform_int_distribution<int> shapeSpawnRange {MIN_FIELD_WIDTH, DEFAULT_FIELD_WIDTH - MIN_FIELD_WIDTH};
};


#endif //TETRIS_GAMESTATE_HPP
