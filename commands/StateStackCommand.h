#ifndef TETRIS_STATESTACKCOMMAND_H
#define TETRIS_STATESTACKCOMMAND_H

#include "../StateStack.h"
#include "Command.h"

class StateStackCommand : public Command {
public:
    explicit StateStackCommand(StateStack& stateStack);
    ~StateStackCommand() override = default;

protected:
    StateStack& stateStack;
};


#endif //TETRIS_STATESTACKCOMMAND_H
