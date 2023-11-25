#ifndef TETRIS_GAMEPAUSESTATE_H
#define TETRIS_GAMEPAUSESTATE_H


#include "State.h"

class GamePauseState : public State {
public:
    GamePauseState(StateStack &stateStack, Context& context);

    bool handleEvent(sf::Event) override;
    bool update(TimePointMs) override;
    bool draw() override;
    bool isTransparent() override;
};


#endif //TETRIS_GAMEPAUSESTATE_H
