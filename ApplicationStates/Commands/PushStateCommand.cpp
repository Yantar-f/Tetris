//
// Created by Shevc on 20/11/2023.
//

#include "PushStateCommand.h"

void PushStateCommand::execute() {
    stateStack.stack.emplace_back(stateStack.createState(stateType));
}

PushStateCommand::PushStateCommand(StateStack& stateStack, StateType stateType) :
    StateStackCommand(stateStack),
    stateType(stateType) {}

