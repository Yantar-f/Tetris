#ifndef TETRIS_STATESTACKCOMMAND_H
#define TETRIS_STATESTACKCOMMAND_H

#include "../ApplicationStates/StateStack.h"
#include "Command.h"

class StateStackCommand : public Command {
public:
    explicit StateStackCommand(StateStack& stateStack);
    virtual ~StateStackCommand() = default;

protected:
    StateStack& stateStack;
};


#endif //TETRIS_STATESTACKCOMMAND_H
