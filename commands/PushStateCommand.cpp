#include "PushStateCommand.hpp"
#include "../FatalTerminationManager.hpp"

PushStateCommand::PushStateCommand(
        StateName stateName,
        std::vector<std::unique_ptr<State>>& stack,
        std::unordered_map<StateName, std::function<std::unique_ptr<State>()>>& stateFactory) :
        stateName(stateName),
        stack(stack),
        stateFactory(stateFactory) {}

void PushStateCommand::execute() {
    LOG_INFO(std::string("Creating state: id = ").append(std::to_string(static_cast<int>(stateName))));

    auto it = stateFactory.find(stateName);

    if (it == stateFactory.end()) {
        LOG_FATAL(std::string("State not found: id = ").append(std::to_string(static_cast<int>(stateName))));
        TERMINATE(EXIT_FAILURE);
    }

    stack.emplace_back(it->second());
}

