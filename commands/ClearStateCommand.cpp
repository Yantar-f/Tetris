#include "ClearStateCommand.h"

void ClearStateCommand::execute() {
    LOG_INFO("Empty entire state stack");
    stack.clear();
}

ClearStateCommand::ClearStateCommand(std::vector<std::unique_ptr<State>>& stack) : stack(stack) {}
