//
// Created by Shevc on 20/11/2023.
//

#include "ClearStateCommand.h"

ClearStateCommand::ClearStateCommand(StateStack& stateStack) : StateStackCommand(stateStack) {}

void ClearStateCommand::execute() {
    stateStack.stack.clear();
}
