#ifndef TETRIS_CLEARSTATECOMMAND_HPP
#define TETRIS_CLEARSTATECOMMAND_HPP

#include "Command.hpp"
#include "../states/State.hpp"

class ClearStateCommand : public Command {
public:
    explicit ClearStateCommand(std::vector<std::unique_ptr<State>>&);
    void execute() override;

private:
    std::vector<std::unique_ptr<State>>& stack;
};


#endif //TETRIS_CLEARSTATECOMMAND_HPP
