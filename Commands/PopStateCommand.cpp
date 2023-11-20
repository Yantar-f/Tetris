#include "PopStateCommand.h"

PopStateCommand::PopStateCommand(StateStack& stateStack) : StateStackCommand(stateStack) {}

void PopStateCommand::execute() {
    stateStack.stack.pop_back();
}