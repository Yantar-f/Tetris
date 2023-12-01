#ifndef TETRIS_GAMESTATE_HPP
#define TETRIS_GAMESTATE_HPP

#include "State.hpp"

class GameState : public State {
public:
    GameState(StateStack &stateStack, Context& context);

    bool handleEvent(sf::Event) override;
    bool update(TimePointMs) override;
    bool draw() override;
    bool isTransparent() override;
};


#endif //TETRIS_GAMESTATE_HPP
