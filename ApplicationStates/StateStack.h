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

class State;

class StateStack {
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

private:
    void applyPendingStackChanges();
    std::unique_ptr<State> createState(StateType);

private:
    std::vector<std::unique_ptr<State>> stack;
    std::unordered_map<StateType, std::function<std::unique_ptr<State>()>> stateFactory;
};

#endif //TETRIS_STATESTACK_H
