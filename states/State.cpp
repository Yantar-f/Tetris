#include "State.h"

State::State(StateStack& stateStack, Context context) : stateStack(stateStack), context(context) {}

void State::requestStackPush(StateType stateType) {
    stateStack.pushState(stateType);
}

void State::requestStackPop() {
    stateStack.popState();
}

void State::requestStateClear() {
    stateStack.clearStates();
}
