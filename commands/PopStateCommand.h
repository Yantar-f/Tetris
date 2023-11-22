#ifndef TETRIS_POPSTATECOMMAND_H
#define TETRIS_POPSTATECOMMAND_H

#include "StateStackCommand.h"

class PopStateCommand : public StateStackCommand {
public:
    explicit PopStateCommand(StateStack&);
    void execute() override;
};


#endif //TETRIS_POPSTATECOMMAND_H
