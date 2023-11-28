#include "State.h"

State::State(StateStack& stateStack, Context& context) : stateStack(stateStack), context(context) {}

void State::requestStackPush(StateName stateName) {
    stateStack.pushState(stateName);
}

void State::requestStackPop() {
    stateStack.popState();
}

void State::requestStateClear() {
    stateStack.clearStates();
}
