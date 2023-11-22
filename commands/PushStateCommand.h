#ifndef TETRIS_PUSHSTATECOMMAND_H
#define TETRIS_PUSHSTATECOMMAND_H

#include "Command.h"
#include "../StateName.h"
#include "../StateStack.h"
#include "StateStackCommand.h"

class PushStateCommand : public StateStackCommand {
public:
    PushStateCommand(StateStack&, StateName);
    void execute() override;

private:
    StateName stateName;
};


#endif //TETRIS_PUSHSTATECOMMAND_H
