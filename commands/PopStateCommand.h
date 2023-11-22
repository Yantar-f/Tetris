#ifndef TETRIS_POPSTATECOMMAND_H
#define TETRIS_POPSTATECOMMAND_H

#include <memory>
#include <vector>
#include "Command.h"
#include "../states/State.h"

class PopStateCommand : public Command {
public:
    explicit PopStateCommand(std::vector<std::unique_ptr<State>>&);
    void execute() override;

private:
    std::vector<std::unique_ptr<State>>& stack;
};


#endif //TETRIS_POPSTATECOMMAND_H
