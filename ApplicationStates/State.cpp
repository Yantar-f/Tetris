//
// Created by Yantar on 16/11/2023.
//

#include "State.h"

State::State(StateStack& stateStack) : stateStack(stateStack) {}

void State::requestStackPush(StateType stateType) {
    stateStack.pushState(stateType);
}

void State::requestStackPop() {

}

