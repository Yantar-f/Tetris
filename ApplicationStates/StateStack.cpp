#include <cassert>
#include "StateStack.h"
#include <unordered_map>

void StateStack::handleEvent(sf::Event) {

}

void StateStack::update(TimePointMs) {

}

void StateStack::draw() {

}

bool StateStack::isEmpty() const {
    return stack.empty();
}

std::unique_ptr<State> StateStack::createState(StatesEnum stateID) {
    auto iterator = stateFactory.find(stateID);
    assert(iterator != stateFactory.end());

    return iterator->second();
}

template<class StateType>
void StateStack::registerState(StatesEnum stateID) {
    stateFactory[stateID] = [this] () {
        return std::unique_ptr<State> (new StateType(*this));
    };
}
