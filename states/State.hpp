#ifndef TETRIS_STATE_HPP
#define TETRIS_STATE_HPP

#include "../StateStack.hpp"
#include "StateName.hpp"
#include "../CommonDefinitions.hpp"
#include "../Context.hpp"

class StateStack;

class State {
public:
    explicit State(StateStack&, Context&);
    virtual ~State() = default;

    virtual bool handleEvent(sf::Event) = 0;
    virtual bool update(TimePointMs) = 0;
    virtual bool draw() = 0;
    virtual bool isTransparent() = 0;

protected:
    void requestStackPush(StateName);
    void requestStackPop();
    void requestStateClear();

protected:
    StateStack& stateStack;
    Context& context;
};


#endif //TETRIS_STATE_HPP
