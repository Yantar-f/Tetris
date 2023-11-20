//
// Created by Shevc on 20/11/2023.
//

#ifndef TETRIS_PUSHSTATECOMMAND_H
#define TETRIS_PUSHSTATECOMMAND_H

#include "Command.h"
#include "../StateType.h"
#include "../StateStack.h"
#include "StateStackCommand.h"

class PushStateCommand : public StateStackCommand {
public:
    PushStateCommand(StateStack&, StateType);
    void execute() override;

private:
    StateType stateType;
};


#endif //TETRIS_PUSHSTATECOMMAND_H
