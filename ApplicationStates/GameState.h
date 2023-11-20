#ifndef TETRIS_GAMESTATE_H
#define TETRIS_GAMESTATE_H

#include "State.h"

class GameState : public State{
public:
    explicit GameState(StateStack&);
    bool handleEvent(sf::Event) override;
    bool update(TimePointMs) override;
    bool draw() override;
};


#endif //TETRIS_GAMESTATE_H
