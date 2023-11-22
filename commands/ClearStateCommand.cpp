#include "ClearStateCommand.h"

ClearStateCommand::ClearStateCommand(StateStack& stateStack) : StateStackCommand(stateStack) {}

void ClearStateCommand::execute() {
    stateStack.stack.clear();
}
