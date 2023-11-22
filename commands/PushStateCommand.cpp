#include "PushStateCommand.h"

#include <utility>

void PushStateCommand::execute() {
    stack.emplace_back(createState());
}

PushStateCommand::PushStateCommand(std::vector<std::unique_ptr<State>>& stack, std::function<std::unique_ptr<State>()>&& createState) :
    stack(stack),
    createState(createState) {}

