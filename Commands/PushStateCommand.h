#ifndef TETRIS_PUSHSTATECOMMAND_H
#define TETRIS_PUSHSTATECOMMAND_H

#include "Command.h"
#include "../ApplicationStates/StateType.h"
#include "../ApplicationStates/StateStack.h"
#include "StateStackCommand.h"

class PushStateCommand : public StateStackCommand {
public:
    PushStateCommand(StateStack&, StateType);
    void execute() override;

private:
    StateType stateType;
};


#endif //TETRIS_PUSHSTATECOMMAND_H
