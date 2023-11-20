#include <unordered_map>
#include "StateStack.h"
#include "../Log/Logger.h"
#include "../FatalTerminationManager.h"
#include "../Commands/ClearStateCommand.h"
#include "../Commands/PopStateCommand.h"
#include "../Commands/PushStateCommand.h"
#include "PreloadAppState.h"

void StateStack::handleEvent(sf::Event event) {
    for (size_t i = stack.size() - 1; i > -1; --i) {
        if (!stack[i]->handleEvent(event)) break;
    }

    applyPendingStackChanges();
}

void StateStack::update(TimePointMs timePoint) {
    for (size_t i = stack.size() - 1; i > -1; --i) {
        if (!stack[i]->update(timePoint)) break;
    }

    applyPendingStackChanges();
}

void StateStack::draw() {
    for (size_t length = stack.size(), i = 0; i < length; ++i) {
        if (!stack[i]->draw()) break; // think about this moment
    }
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

void StateStack::applyPendingStackChanges() {
    for (size_t length = pendingChanges.size(), i = 0; i < length; ++i) {
        pendingChanges[i]->execute();
    }

    pendingChanges.clear();
}

void StateStack::pushState(StateType stateType) {
    pendingChanges.push_back(std::unique_ptr<Command>(new PushStateCommand(*this, stateType)));
}

void StateStack::popState() {
    pendingChanges.push_back(std::unique_ptr<Command>(new PopStateCommand(*this)));
}

void StateStack::clearStates() {
    pendingChanges.push_back(std::unique_ptr<Command>(new ClearStateCommand(*this)));
}
