#ifndef TETRIS_STATE_H
#define TETRIS_STATE_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../StateStack.h"
#include "../StateName.h"
#include "../CommonDefinitions.h"
#include "../Context.h"

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


#endif //TETRIS_STATE_H
