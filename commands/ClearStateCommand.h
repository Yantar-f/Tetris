#ifndef TETRIS_CLEARSTATECOMMAND_H
#define TETRIS_CLEARSTATECOMMAND_H

#include "Command.h"
#include "../states/State.h"

class ClearStateCommand : public Command {
public:
    explicit ClearStateCommand(std::vector<std::unique_ptr<State>>&);
    void execute() override;

private:
    std::vector<std::unique_ptr<State>>& stack;
};


#endif //TETRIS_CLEARSTATECOMMAND_H
