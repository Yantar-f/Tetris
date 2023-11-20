#include "State.h"

State::State(StateStack& stateStack) : stateStack(stateStack) {}

void State::requestStackPush(StateType stateType) {
    stateStack.pushState(stateType);
}

void State::requestStackPop() {
    stateStack.popState();
}

void State::requestStateClear() {
    stateStack.clearStates();
}
