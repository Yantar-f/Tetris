#include "StateStack.h"
#include "Commands/ClearStateCommand.h"
#include "Commands/PopStateCommand.h"
#include "Commands/PushStateCommand.h"

#include "SFML/Graphics.hpp"

StateStack::StateStack(Context& context) : context(context) {
    stack.reserve(20);
    pendingCommands.reserve(40);
}

void StateStack::handleEvent(sf::Event event) {
    for (auto it = stack.rbegin(); it != stack.rend(); ++it) {
        if (!(*it)->handleEvent(event)) break;
    }

    executePendingCommands();
}

void StateStack::update(TimePointMs timePoint) {
    for (auto it = stack.rbegin(); it != stack.rend(); ++it) {
        if (!(*it)->update(timePoint)) break;
    }

    executePendingCommands();
}

void StateStack::draw() {
    context.renderWindow.clear();
    auto it = stack.rbegin();

    if (it == stack.rend()) return;

    while (it != stack.rend() && (*it)->isTransparent()) ++it;

    if (it == stack.rend()) --it;

    do {
        (*it)->draw();
        --it;
    } while (it >= stack.rbegin());

    context.renderWindow.display();
}

bool StateStack::isEmpty() const {
    return stack.empty();
}

void StateStack::executePendingCommands() {
    for (auto& pendingCommand : pendingCommands) {
        pendingCommand->execute();
    }

    pendingCommands.clear();
}

void StateStack::pushState(StateName stateName) {
    pendingCommands.emplace_back(new PushStateCommand(stateName, stack, stateFactory));
}

void StateStack::popState() {
    pendingCommands.emplace_back(new PopStateCommand(stack));
}

void StateStack::clearStates() {
    pendingCommands.emplace_back(new ClearStateCommand(stack));
}
