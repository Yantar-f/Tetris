#include <unordered_map>
#include "StateStack.h"
#include "../Log/Logger.h"
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
    size_t length = stack.size();
    for (size_t i = 0; i < length; ++i) {
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
        TERMINATE(1);
    }

    return it->second();
}

template<class StateToCreate>
void StateStack::registerState(StateType stateType) {
    stateFactory[stateType] = [this, stateType] () {
        LOG_INFO(std::string("Registering state: id = ").append(std::to_string(stateType)));
        return std::unique_ptr<State> (new StateToCreate(*this));
    };
}
