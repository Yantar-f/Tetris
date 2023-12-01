#include "PopStateCommand.hpp"

PopStateCommand::PopStateCommand(std::vector<std::unique_ptr<State>>& stack) : stack(stack) {}

void PopStateCommand::execute() {
    LOG_INFO("Pop state");
    stack.pop_back();
}