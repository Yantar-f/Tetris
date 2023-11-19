#ifndef TETRIS_STATE_H
#define TETRIS_STATE_H

#include <SFML/Window/Event.hpp>
#include "StateStack.h"
#include "../CommonTypedefs.h"

class StateStack;

class State {
public:
    explicit State(StateStack&);
    virtual ~State() = default;
    virtual bool handleEvent(sf::Event) = 0;
    virtual bool update(TimePointMs) = 0;
    virtual bool draw() = 0;
private:
    StateStack& stateStack;
};


#endif //TETRIS_STATE_H
