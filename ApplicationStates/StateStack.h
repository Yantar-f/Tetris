#ifndef TETRIS_STATESTACK_H
#define TETRIS_STATESTACK_H

#include <memory>
#include <vector>
#include <functional>
#include <unordered_map>
#include "State.h"
#include "../CommonDefinitions.h"
#include "StateType.h"
#include "../Commands/Command.h"
#include "../Log/Logger.h"
#include "../Context.h"

class State;

class StateStack {
    friend class PushStateCommand;
    friend class PopStateCommand;
    friend class ClearStateCommand;

public:
    explicit StateStack(Context);
    void handleEvent(sf::Event);
    void update(TimePointMs);
    void draw();
    bool isEmpty() const;

    template<typename StateToCreate>
    void registerState(StateType);

    void pushState(StateType);
    void popState();
    void clearStates();

private:
    std::unique_ptr<State> createState(StateType);
    void applyPendingStackChanges();

private:
    Context context;
    std::vector<std::unique_ptr<State>> stack;
    std::vector<std::unique_ptr<Command>> pendingChanges;
    std::unordered_map<StateType, std::function<std::unique_ptr<State>()>> stateFactory;
};

template<typename StateToCreate>
void StateStack::registerState(StateType stateType) {
    LOG_INFO(std::string("Registering state: id = ").append(std::to_string(stateType)));
    stateFactory[stateType] = [this] () { return std::unique_ptr<State> (new StateToCreate(*this, context));};
}

#endif //TETRIS_STATESTACK_H
