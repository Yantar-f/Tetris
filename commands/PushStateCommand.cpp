#include "PushStateCommand.h"

void PushStateCommand::execute() {
    stateStack.stack.emplace_back(stateStack.createState(stateName));
}

PushStateCommand::PushStateCommand(StateStack& stateStack, StateName stateName) :
    StateStackCommand(stateStack),
    stateName(stateName) {}

