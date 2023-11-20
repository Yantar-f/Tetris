//
// Created by Shevc on 20/11/2023.
//

#include "PopStateCommand.h"

PopStateCommand::PopStateCommand(StateStack& stateStack) : StateStackCommand(stateStack) {}

void PopStateCommand::execute() {
    stateStack.stack.pop_back();
}