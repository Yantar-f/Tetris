#ifndef TETRIS_PUSHSTATECOMMAND_H
#define TETRIS_PUSHSTATECOMMAND_H

#include "Command.h"
#include "../StateName.h"
#include "../StateStack.h"

class PushStateCommand : public Command {
public:
    PushStateCommand(
        StateName,
        std::vector<std::unique_ptr<State>>&,
        std::unordered_map<StateName, std::function<std::unique_ptr<State>()>>&
    );

    void execute() override;

private:
    StateName stateName;
    std::vector<std::unique_ptr<State>>& stack;
    std::unordered_map<StateName, std::function<std::unique_ptr<State>()>>& stateFactory;
};


#endif //TETRIS_PUSHSTATECOMMAND_H
