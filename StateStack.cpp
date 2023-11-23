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

    executePendingCommands();
}

void StateStack::update(TimePointMs timePoint) {
    for (auto it = stack.rbegin(); it != stack.rend(); ++it) {
        if (!(*it)->update(timePoint)) break;
    }

    executePendingCommands();
}

void StateStack::draw() {
    context.renderWindow.clear();
    auto it = stack.rbegin();

    if (it == stack.rend()) return;

    while (it != stack.rend() && (*it)->isTransparent()) ++it;
    while (it >= stack.rbegin()) {
        (*it)->draw();
        --it;
    }

    context.renderWindow.display();
}

bool StateStack::isEmpty() const {
    return stack.empty();
}

std::unique_ptr<State> StateStack::createState(StateName stateName) {
    LOG_INFO(std::string("Creating state: id = ").append(std::to_string(stateName)));

    auto it = stateFactory.find(stateName);

    if (it == stateFactory.end()) {
        LOG_FATAL(std::string("State not found: id = ").append(std::to_string(stateName)));
        TERMINATE(EXIT_FAILURE);
    }

    return it->second();
}

void StateStack::executePendingCommands() {
    for (auto& pendingCommand : pendingCommands) {
        pendingCommand->execute();
    }

    pendingCommands.clear();
}

void StateStack::pushState(StateName stateName) {
    pendingCommands.emplace_back(new PushStateCommand(stack, std::function<std::unique_ptr<State>()> ([this, stateName] () {
        return this->createState(stateName);
    })));
}

void StateStack::popState() {
    pendingCommands.emplace_back(new PopStateCommand(stack));
}

void StateStack::clearStates() {
    pendingCommands.emplace_back(new ClearStateCommand(stack));
}

StateStack::StateStack(Context context) : context(context) {
    stack.reserve(20);
    pendingCommands.reserve(40);
}
