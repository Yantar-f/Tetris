#ifndef TETRIS_PUSHSTATECOMMAND_H
#define TETRIS_PUSHSTATECOMMAND_H

#include "Command.h"
#include "../StateName.h"
#include "../StateStack.h"

class PushStateCommand : public Command {
public:
    PushStateCommand(std::vector<std::unique_ptr<State>>&, std::function<std::unique_ptr<State>()>&);
    void execute() override;

private:
    std::vector<std::unique_ptr<State>>& stack;
    std::function<std::unique_ptr<State>()> createState;
};


#endif //TETRIS_PUSHSTATECOMMAND_H
