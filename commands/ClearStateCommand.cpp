#include "ClearStateCommand.h"

void ClearStateCommand::execute() {
    stack.clear();
}

ClearStateCommand::ClearStateCommand(std::vector<std::unique_ptr<State>>& stack) : stack(stack) {}
