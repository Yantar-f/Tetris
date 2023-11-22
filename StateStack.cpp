#include <unordered_map>
#include "StateStack.h"
#include "Log/Logger.h"
#include "FatalTerminationManager.h"
#include "Commands/ClearStateCommand.h"
#include "Commands/PopStateCommand.h"
#include "Commands/PushStateCommand.h"
#include "SFML/Graphics.hpp"

void StateStack::handleEvent(sf::Event event) {
    for (auto it = stack.rbegin(); it != stack.rend(); ++it) {
        if (!(*it)->handleEvent(event)) break;
    }

    executePendingSCommands();
}

void StateStack::update(TimePointMs timePoint) {
    for (auto it = stack.rbegin(); it != stack.rend(); ++it) {
        if (!(*it)->update(timePoint)) break;
    }

    executePendingSCommands();
}

void StateStack::draw() {
    context.renderWindow.clear();
    auto it = stack.rbegin();

    while (it != stack.rend() && (*it)->isTransparent()) ++it;
    while (it <= stack.rbegin()) {
        (*it)->draw();
        ++it;
    }

    context.renderWindow.display();
}

bool StateStack::isEmpty() const {
    return stack.empty();
}

std::unique_ptr<State> StateStack::createState(StateType stateType) {
    LOG_INFO(std::string("Creating state: id = ").append(std::to_string(stateType)));

    auto it = stateFactory.find(stateType);

    if (it == stateFactory.end()) {
        LOG_FATAL(std::string("State not found: id = ").append(std::to_string(stateType)));
        TERMINATE(EXIT_FAILURE);
    }

    return it->second();
}

void StateStack::executePendingSCommands() {
    for (auto& pendingCommand : pendingCommands) {
        pendingCommand->execute();
    }

    pendingCommands.clear();
}

void StateStack::pushState(StateType stateType) {
    pendingCommands.emplace_back(new PushStateCommand(*this, stateType));
}

void StateStack::popState() {
    pendingCommands.emplace_back(new PopStateCommand(*this));
}

void StateStack::clearStates() {
    pendingCommands.emplace_back(new ClearStateCommand(*this));
}

StateStack::StateStack(Context context) : context(context) {}
