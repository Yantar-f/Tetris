#ifndef TETRIS_STATESTACK_H
#define TETRIS_STATESTACK_H

#pragma once
#include <memory>
#include <vector>
#include <functional>
#include <unordered_map>
#include "State.h"
#include "../CommonTypedefs.h"
#include "StateType.h"
#include "Commands/StateStackCommand.h"

class State;
class StateStackCommand;

class StateStack {
    friend class PushStateCommand;
    friend class PopStateCommand;
    friend class ClearStateCommand;

public:
    void handleEvent(sf::Event);
    void update(TimePointMs);
    void draw();
    bool isEmpty() const;

    template<class StateToCreate>
    void registerState(StateType);

    void pushState(StateType);
    void popState();
    void clearStates();

protected:
    std::unique_ptr<State> createState(StateType);

private:
    void applyPendingStackChanges();

private:
    std::vector<std::unique_ptr<State>> stack;
    std::vector<std::unique_ptr<StateStackCommand>> pendingStackChanges;
    std::unordered_map<StateType, std::function<std::unique_ptr<State>()>> stateFactory;
};

#endif //TETRIS_STATESTACK_H
