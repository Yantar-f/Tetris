//
// Created by Shevc on 20/11/2023.
//

#ifndef TETRIS_STATESTACKCOMMAND_H
#define TETRIS_STATESTACKCOMMAND_H


#include "../StateStack.h"
#include "Command.h"

class StateStack;

class StateStackCommand : public Command {
public:
    explicit StateStackCommand(StateStack& stateStack);

protected:
    StateStack& stateStack;
};


#endif //TETRIS_STATESTACKCOMMAND_H
