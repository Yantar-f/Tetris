#include <cassert>
#include <unordered_map>
#include "StateStack.h"
#include "../Logger.h"
#include "../FatalTerminationManager.h"

void StateStack::handleEvent(sf::Event event) {
    for (size_t i = stack.size() - 1; i > -1; --i) {
        if (!stack[i]->handleEvent(event)) break;
    }
}

void StateStack::update(TimePointMs timePoint) {
    for (size_t i = stack.size() - 1; i > -1; --i) {
        if (!stack[i]->update(timePoint)) break;
    }
}

void StateStack::draw() {
    for (size_t i = stack.size() - 1; i > -1; --i) {
        if (!stack[i]->draw()) break;
    }
}

bool StateStack::isEmpty() const {
    return stack.empty();
}

std::unique_ptr<State> StateStack::createState(StatesEnum stateID) {
    LOG_INFO(std::string("Creating state: id = ").append(std::to_string(stateID)));

    auto it = stateFactory.find(stateID);

    if (it == stateFactory.end()) {
        LOG_FATAL(std::string("State not found: id = ").append(std::to_string(stateID)));
        FatalTerminationManager::terminateApp(1);
    }

    return it->second();
}

template<class StateType>
void StateStack::registerState(StatesEnum stateID) {
    stateFactory[stateID] = [this, stateID] () {
        LOG_INFO(std::string("Registering state: id = ").append(std::to_string(stateID)));
        return std::unique_ptr<State> (new StateType(*this));
    };
}
