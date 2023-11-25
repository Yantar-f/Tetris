#include "PushStateCommand.h"
#include "../FatalTerminationManager.h"

void PushStateCommand::execute() {
    LOG_INFO(std::string("Creating state: id = ").append(std::to_string(stateName)));

    auto it = stateFactory.find(stateName);

    if (it == stateFactory.end()) {
        LOG_FATAL(std::string("State not found: id = ").append(std::to_string(stateName)));
        TERMINATE(EXIT_FAILURE);
    }

    stack.emplace_back(it->second());
}

PushStateCommand::PushStateCommand(
    StateName stateName,
    std::vector<std::unique_ptr<State>>& stack,
    std::unordered_map<StateName, std::function<std::unique_ptr<State>()>>& stateFactory) :
    stateName(stateName),
    stack(stack),
    stateFactory(stateFactory) {}

