#ifndef TETRIS_GAMESTATE_HPP
#define TETRIS_GAMESTATE_HPP

#include "State.hpp"

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
    bool field[DEFAULT_FIELD_WIDTH][DEFAULT_FIELD_HEIGHT] {};
    sf::RectangleShape boxShape;
    sf::RectangleShape cellShape;
    sf::Vector2i playerShapePosition;
};


#endif //TETRIS_GAMESTATE_HPP
