//
// Created by Shevc on 20/11/2023.
//

#ifndef TETRIS_CLEARSTATECOMMAND_H
#define TETRIS_CLEARSTATECOMMAND_H

#include "StateStackCommand.h"

class ClearStateCommand : public StateStackCommand {
public:
    explicit ClearStateCommand(StateStack&);
    void execute() override;
};


#endif //TETRIS_CLEARSTATECOMMAND_H
