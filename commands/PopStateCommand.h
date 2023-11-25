#ifndef TETRIS_POPSTATECOMMAND_H
#define TETRIS_POPSTATECOMMAND_H

#include "Command.h"
#include "../states/State.h"

#include <memory>
#include <vector>

class PopStateCommand : public Command {
public:
    explicit PopStateCommand(std::vector<std::unique_ptr<State>>&);
    void execute() override;

private:
    std::vector<std::unique_ptr<State>>& stack;
};


#endif //TETRIS_POPSTATECOMMAND_H
