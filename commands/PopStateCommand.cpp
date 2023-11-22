#include "PopStateCommand.h"

PopStateCommand::PopStateCommand(std::vector<std::unique_ptr<State>>& stack) : stack(stack) {}

void PopStateCommand::execute() {
    stack.pop_back();
}