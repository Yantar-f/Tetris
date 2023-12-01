#ifndef TETRIS_POPSTATECOMMAND_HPP
#define TETRIS_POPSTATECOMMAND_HPP

#include "Command.hpp"
#include "../states/State.hpp"

#include <memory>
#include <vector>

class PopStateCommand : public Command {
public:
    explicit PopStateCommand(std::vector<std::unique_ptr<State>>&);
    void execute() override;

private:
    std::vector<std::unique_ptr<State>>& stack;
};


#endif //TETRIS_POPSTATECOMMAND_HPP
