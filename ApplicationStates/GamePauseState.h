#ifndef TETRIS_GAMEPAUSESTATE_H
#define TETRIS_GAMEPAUSESTATE_H


#include "State.h"

class GamePauseState : public State {
public:
    explicit GamePauseState(StateStack&);
    bool handleEvent(sf::Event) override;
    bool update(TimePointMs) override;
    bool draw() override;
};


#endif //TETRIS_GAMEPAUSESTATE_H
