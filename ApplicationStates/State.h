#ifndef TETRIS_STATE_H
#define TETRIS_STATE_H

#include <SFML/Window/Event.hpp>
#include "StateStack.h"
#include "StateType.h"
#include "../CommonDefinitions.h"

class StateStack;

class State {
public:
    explicit State(StateStack&);
    virtual ~State() = default;
    virtual bool handleEvent(sf::Event) = 0;
    virtual bool update(TimePointMs) = 0;
    virtual bool draw() = 0;

protected:
    void requestStackPush(StateType);
    void requestStackPop();
    void requestStateClear();

private:
    StateStack& stateStack;
};


#endif //TETRIS_STATE_H
